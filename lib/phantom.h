// Copyright (c) 2015 Vitaly Slobodin <vitaliy.slobodin@gmail.com>
// All rights reserved. Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef PHANTOM_H_
#define PHANTOM_H_

#include "module.h"

namespace lib {

#define VERSION "3.0.0"

class Phantom : public Module {

 public:
  Phantom();

  bool Execute(const CefString &name,
               CefRefPtr<CefV8Value> object,
               const CefV8ValueList &arguments,
               CefRefPtr<CefV8Value> &return_value,
               CefString &exception) OVERRIDE;
};

} // namespace lib

#endif /* PHANTOM_H_ */
