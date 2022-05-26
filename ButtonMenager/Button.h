#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

enum Type {MONOSTABLE, BISTABLE};

class Button
{
private:
  long _debouncingTime;
  long _lastTime;
  void* _functionToExecute;
  boolean _actualState;
  boolean _lastState;
  boolean _isDebouncingExecuting;
  Type _buttonType;
  int _pinNumber;
  void _executeDebouncing();
  void _executeBaseOnType();
public:
  Button();

  void setDebouncing(long);
  void begin(int, boolean, void*, Type, long);
  void execute(long);
};


#endif
