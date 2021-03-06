;;
;; Upcaste Performance Libraries
;; Copyright (C) 2012-2013 Jesse W. Towner
;;
;; Permission is hereby granted, free of charge, to any person obtaining
;; a copy of this software and associated documentation files (the
;; "Software"), to deal in the Software without restriction, including
;; without limitation the rights to use, copy, modify, merge, publish,
;; distribute, sublicense, and/or sell copies of the Software, and to
;; permit persons to whom the Software is furnished to do so, subject to
;; the following conditions:
;;
;; The above copyright notice and this permission notice shall be
;; included in all copies or substantial portions of the Software.
;;
;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
;; IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
;; CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
;; TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
;; SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
;;

INCLUDE fenv.inc

;;
;; int fetestexcept(int excepts);
;;
;; Tests current exception status flags with those specified by caller.
;;
;; Input:
;;          ecx = excepts
;; Output:
;;          rax = bitwise inclusive-or of exception status flags set
;;

.CODE
ALIGN 8
PUBLIC fetestexcept
fetestexcept PROC

    xor         rax, rax
    stmxcsr     DWORD PTR [rsp-4]
    fnstsw      ax
    and         ecx, FE_ALL_EXCEPT
    or          eax, DWORD PTR [rsp-4]
    and         eax, ecx
    ret

fetestexcept ENDP

END
