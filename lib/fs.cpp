#include "fs.h"

namespace lib {

FileSystem::FileSystem()
{
  // initialize functions
  PutFunction(m_module, "open");
}

bool FileSystem::Open(const CefString &path)
{
  // TODO: Implement
  return false;
}

} // namespace lib
