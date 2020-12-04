include "cefpython.pyx"
include "browser.pyx"

cdef public void PrintToPDF_OnPdfPrintFinished(
        CefRefPtr[CefBrowser] cefBrowser,
        const CefString& path,
        cpp_bool ok
        ) except * with gil:
    cdef PyBrowser pyBrowser
    cdef py_string pyPath
    cdef object callback
    try:
        assert IsThread(TID_IO), "Must be called on the IO thread"
        print("start")
        pyBrowser = GetPyBrowser(cefBrowser, "OnPdfPrintFinished")
        print("browser")
        pyPath = CefToPyString(path)
        print("path")
        callback = pyBrowser.GetClientCallback("OnPdfPrintFinished")
        print("callback")
        if callback:
            print("got")
            callback(path=pyPath, ok=ok)
            print("done")
    except:
        (exc_type, exc_value, exc_trace) = sys.exc_info()
        sys.excepthook(exc_type, exc_value, exc_trace)
