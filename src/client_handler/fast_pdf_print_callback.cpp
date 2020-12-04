#include "fast_pdf_print_callback.h"
#include "include/cef_browser.h"

void CefFastPdfPrintCallback::OnPdfPrintFinished(
        CefRefPtr<CefBrowser> browser, const CefString& path, bool ok
        ) {
    REQUIRE_UI_THREAD();
    std::string msg = "[Browser process] PDF Printing Completed, saved to: ";
    msg.append(path);
    LOG(INFO) << msg.c_str();
    PrintToPDF_OnPdfPrintFinished(browser, path, ok);
}