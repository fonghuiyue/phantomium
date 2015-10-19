// Copyright (c) 2015 Klaralvdalens Datakonsult AB (KDAB).
// All rights reserved. Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef CEF_TESTS_PHANTOMJS_APP_H_
#define CEF_TESTS_PHANTOMJS_APP_H_

#include "include/cef_app.h"
#include "phantom/phantom.h"

class PhantomJSApp : public CefApp,
                     public CefBrowserProcessHandler,
                     public CefRenderProcessHandler {
 public:
  PhantomJSApp();
  ~PhantomJSApp();

  static CefRefPtr<WebPage> CreateWebPage();

  // CefApp methods:
  virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE
  {
    return this;
  }

  virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE
  {
    return this;
  }

  // CefBrowserProcessHandler methods:
  void OnContextInitialized() OVERRIDE;

  // CefRenderProcessHandler methods:
  void OnContextCreated(CefRefPtr<CefBrowser> browser,
                        CefRefPtr<CefFrame> frame,
                        CefRefPtr<CefV8Context> context) OVERRIDE;
  CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler()
    OVERRIDE { return this; }

 private:
  void Require(const CefString& path);

  // CefRenderProcessHandler methods:
  void OnWebKitInitialized() OVERRIDE;
  void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                        CefRefPtr<CefV8Context> context) OVERRIDE;

 private:
  CefRefPtr<lib::Phantom> m_phantom;
  std::set<CefRefPtr<WebPage>> m_web_pages;
  IMPLEMENT_REFCOUNTING(PhantomJSApp);
};

#endif  // CEF_TESTS_PHANTOMJS_APP_H_
