#define _STOP FF
#define _SSTORE 55
#define _PUSH32 7F

#define ZERO256 0000000000000000000000000000000000000000000000000000000000000000

#define SSTORE(a, b) _PUSH32 a _PUSH32 b _SSTORE

#define RO(arg, rest...) ZERO256 rest
#define INIT(code) code
#define BODY(code) code
#define EXIT(code) code

#define CONTRACT(rodata, init, body, exit) init body exit rodata


// rodata offsets
#define decimals_ 0
#define typehash_ 32

// storage offsets
#define totalsupply_ 0

CONTRACT(
  RO(decimals_, RO(typehash_)),
  INIT(),
  BODY(
    SSTORE(totalsupply_, ZERO256)
  ),
  EXIT()
)
