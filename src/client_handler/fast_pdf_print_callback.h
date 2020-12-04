#include "common/cefpython_public_api.h"


class CefFastPdfPrintCallback : public CefPdfPrintCallback
{
  public:
    explicit CefFastPdfPrintCallback(CefRefPtr<CefBrowser> browser)
        : browser_(browser) {}
    virtual void OnPdfPrintFinished(CefRefPtr<CefBrowser> browser, const CefString& path, bool ok);

  protected:
    CefRefPtr<CefBrowser> browser_;
    IMPLEMENT_REFCOUNTING(CefFastPdfPrintCallback);
};