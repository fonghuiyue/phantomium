// Copyright (c) 2015 Klaralvdalens Datakonsult AB (KDAB).
// All rights reserved. Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef CEF_TESTS_PHANTOMJS_HANDLER_H_
#define CEF_TESTS_PHANTOMJS_HANDLER_H_

#include "include/cef_client.h"

#include <list>

class PhantomJSHandler : public CefClient,
                         public CefDisplayHandler,
                         public CefLifeSpanHandler,
                         public CefLoadHandler,
                         public CefRenderHandler
{
 public:
  PhantomJSHandler();
  ~PhantomJSHandler();

  // Provide access to the single global instance of this object.
  static PhantomJSHandler* GetInstance();

  // CefClient methods:
  CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE
  {
    return this;
  }
  CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE
  {
    return this;
  }
  CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE
  {
    return this;
  }
  CefRefPtr<CefRenderHandler> GetRenderHandler() OVERRIDE
  {
    return this;
  }
  bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message) OVERRIDE;

  // CefDisplayHandler methods:
  bool OnConsoleMessage(CefRefPtr<CefBrowser> browser,
                             const CefString& message,
                             const CefString& source,
                             int line) OVERRIDE;

  // CefLifeSpanHandler methods:
  void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
  bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
  void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

  // CefLoadHandler methods:
  void OnLoadError(CefRefPtr<CefBrowser> browser,
                           CefRefPtr<CefFrame> frame,
                           ErrorCode errorCode,
                           const CefString& errorText,
                           const CefString& failedUrl) OVERRIDE;
  void OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
                                    bool isLoading,
                                    bool canGoBack,
                                    bool canGoForward) OVERRIDE;

  // CefRenderHandler methods:
  bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) OVERRIDE;
  void OnPaint(CefRefPtr<CefBrowser> browser,
                       PaintElementType type,
                       const RectList& dirtyRects,
                       const void* buffer, int width, int height) OVERRIDE;

  // Request that all existing browser windows close.
  void CloseAllBrowsers(bool force_close);

  bool IsClosing() const { return is_closing_; }

 private:
  // List of existing browser windows. Only accessed on the CEF UI thread.
  typedef std::list<CefRefPtr<CefBrowser> > BrowserList;
  BrowserList browser_list_;

  bool is_closing_;

  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(PhantomJSHandler);
};

#endif  // CEF_TESTS_PHANTOMJS_HANDLER_H_
