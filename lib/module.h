// Copyright (c) 2015 Vitaly Slobodin <vitaliy.slobodin@gmail.com>
// All rights reserved. Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef MODULE_H_
#define MODULE_H_

#include <include/cef_v8.h>

namespace lib {

class Module : public CefV8Handler {

 public:
  Module();
  virtual ~Module();
  virtual bool Execute(const CefString &name,
               CefRefPtr<CefV8Value> object,
               const CefV8ValueList &arguments,
               CefRefPtr<CefV8Value> &return_value,
               CefString &exception) { return false; }
  void Register(CefRefPtr<CefV8Value> object);

 protected:
  void PutFunction(const CefString &name);
  void PutProperty(const CefString &name,
                   const CefRefPtr<CefV8Value> &value);

 protected:
  CefRefPtr<CefV8Value> m_module;
  CefString m_name;

  IMPLEMENT_REFCOUNTING(Module);
};

} // namespace lib

#endif /* MODULE_H_ */
