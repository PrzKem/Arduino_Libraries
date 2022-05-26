#include "Button.h"

Button::Button()
{

}

boolean Button::_executeDebouncing(long actualTime){
  this -> _actualState = digitalRead(_pinNumber);

  if (_actualState != _lastState) {
    _lastTime = actualTime;
  }
}


void Button::setDebouncing(long debouncingTime){
  this -> _debouncingTime = debouncingTime;
}


void Button::begin(int pinNumber, boolean isDebouncingExecuting=true, void* functionToExecute, Type buttonType = MONOSTABLE, long debouncingTime=200){
  this -> _pinNumber = (pinNumber>0)?pinNumber:-pinNumber;
  this -> _isDebouncingExecuting = isDebouncingExecuting;
  this -> _functionToExecute = functionToExecute;
  this -> _buttonType = _buttonType;
  this -> _debouncingTime = (debouncingTime>0)?debouncingTime:-debouncingTime;

  pinMode(_pinNumber,INPUT_PULLUP);
  this -> _actualState = digitalRead(_pinNumber);
  this -> _lastState = _actualState;
  this -> _lastTime = millis();
}

void Button::_executeBaseOnType()
{
  if(_buttonType == MONOSTABLE)
  {
    if(_actualState == LOW)
    {
      this -> functionToExecute();
    }
  }
  else
  {
    this -> functionToExecute();
  }
}


void Button::execute(long actualTime = millis()){
  if(_isDebouncingExecuting)
  {
    this -> checkDebouncing(actualTime);
    if(actualTime - _lastTime >= _debouncingTime)
    {
      this -> executeBaseOnType();
    }
    _lastState = _actualState;
    return;
  }

  if(~_isDebouncingExecuting && _lastState != _actualState)
  {
    this -> executeBaseOnType();
    _lastState = _actualState;
    return;
  }
}
