#include "module.h"

namespace lib {

Module::Module()
{
  m_module = CefV8Value::CreateObject(NULL);
}

Module::~Module()
{

}

void Module::Register(CefRefPtr<CefV8Value> object)
{
  object->SetValue(this->m_name, m_module, V8_PROPERTY_ATTRIBUTE_READONLY);
}

void Module::PutFunction(const CefString &name)
{
  m_module->SetValue(name,
                     CefV8Value::CreateFunction(name, this),
                     V8_PROPERTY_ATTRIBUTE_READONLY);
}

void Module::PutProperty(const CefString &name,
                         const CefRefPtr<CefV8Value> &value)
{
  m_module->SetValue(name,
                     value,
                     V8_PROPERTY_ATTRIBUTE_READONLY);
}

} // namespace lib
