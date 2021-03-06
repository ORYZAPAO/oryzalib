#ifndef __SUBJECT_BASE_H__
#define __SUBJECT_BASE_H__
/*
 * Subject Interface
 */

namespace myspace{

class Subject_Base{
  friend class Subject_Base;

  virtual void RegistObserver(Observer_Base *pOb) = 0;
  virtual void RemoveObserver(Observer_Base *pOb)=0;
  virtual void NotifyObserbers(void)=0;
};

};
#endif // __SUBJECT_BASE_H__
