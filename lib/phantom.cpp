#include "phantom.h"

namespace lib {

Phantom::Phantom()
{
  m_name = CefString("phantom");

  PutProperty("version", CefV8Value::CreateString(VERSION));
}

bool Phantom::Execute(const CefString &name,
                      CefRefPtr<CefV8Value> object,
                      const CefV8ValueList &arguments,
                      CefRefPtr<CefV8Value> &return_value,
                      CefString &exception)
{
  if (name == "exit") {

    return true;
  } else if (name == "libraryPath") {
    //return_value = CefV8Value::Crea
    return true;
  }

  return false;
}

} // namespace lib
