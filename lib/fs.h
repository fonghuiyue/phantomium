// Copyright (c) 2015 Vitaly Slobodin <vitaliy.slobodin@gmail.com>
// All rights reserved. Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

namespace lib {

class FileSystem : public Module {

 public:
  FileSystem();
  bool Open(const CefString &path);
};

} // namespace lib
