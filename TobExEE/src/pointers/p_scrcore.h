//TobExEE
#ifndef P_SCRCORE_H
#define P_SCRCORE_H

#ifdef __2014

  #define G_PACTIONTEMP	0X960BC8

  #define IDENTIFIERS_CONSTRUCT0 0X4094C0
  #define IDENTIFIERS_CONSTRUCT1 0X409540
  #define IDENTIFIERS_DECONSTRUCT 0X4095B0
  #define IDENTIFIERS_FINDBYHEAD 0X409AD0

  #define CVARIABLE_SETNAME 0X43C110
  #define CVARIABLE_CONSTRUCT 0X43C9D0
  #define CVARIABLE_OPASSIGN 0X474780
  #define CVARIABLE_GETNAME 0X4D05C0

  #define CVARIABLEMAP_CONSTRUCT 0X57AA70
  #define CVARIABLEMAP_DECONSTRUCT 0X57AAF0
  #define CVARIABLEMAP_ADD 0X57AB20
  #define CVARIABLEMAP_FIND 0X57ADB0
  #define CVARIABLEMAP_GETHASH 0X57AF80
  #define CVARIABLEMAP_EMPTY 0X57B040
  #define CVARIABLEMAP_SETSIZE 0X57B4F0

  #define OBJECT_DECONSTRUCT 0X403F60
  #define OBJECT_CONSTRUCT1 0X404400
  #define OBJECT_CONSTRUCT10 0X409DE0
  #define OBJECT_CONSTRUCT8 0X409E90
  #define OBJECT_MATCHCRITERIA 0X409F40
  #define OBJECT_OPASSIGN 0X40A6B0
  #define OBJECT_DECODEIDENTIFIERS 0X40A750
  #define OBJECT_FINDTARGETOFTYPE 0X40C900
  #define OBJECT_FINDTARGET 0X40C990
  #define OBJECT_SETIDENTIFIERS 0X40CBC0
  #define OBJECT_GETOPPOSINGEAOBJECT 0X40CD90
  #define OBJECT_GETDUALCLASSES 0X40CE10
  #define OBJECT_ISEQUALINCLUDEENUM 0X40D440

  #define G_OBJECT_ANY 0X960868
  #define G_OBJECT_ANYTHING 0X96087C
  #define G_OBJECT_NOTHING 0X960890
  #define G_OBJECT_NONSCRIPT 0X9608A4
  #define G_OBJECT_MYSELF 0X9608B8

  #define TRIGGER_CONSTRUCT3 0X41AE80
  #define TRIGGER_CONSTRUCT2 0X41AF30
  #define TRIGGER_OPASSIGN 0X4092A0
  #define TRIGGER_DECODEIDENTIFIERS 0X404430


  #define ACTION_CONSTRUCT0 0X403E50
  #define ACTION_DECONSTRUCT 0X403F10
  #define ACTION_OPASSIGN 0X409040

  #define RESPONSE_CONSTRUCT0 0X40D7B0
  #define RESPONSE_DECONSTRUCT0 0X40DCB0
  #define RESPONSE_OPASSIGN 0X40D880

  #define CSCRIPTBLOCK_EVALUATE 0X404170
  #define CSCRIPTBLOCK_EVALUATETRIGGER 0X404220

  #define CSCRIPTPARSER_GETTRIGGEROPCODE 0X416BE0
  #define CSCRIPTPARSER_GETOPCODE 0X417060
  #define CSCRIPTPARSER_SETERROR 0X417110
  #define CSCRIPTPARSER_PARSEOBJECT 0X417190
  #define CSCRIPTPARSER_SPANBEFORE 0X4177B0
  #define CSCRIPTPARSER_SPANAFTER 0X417860
  #define CSCRIPTPARSER_GETARGTEXT 0X41A750
  #define CSCRIPTPARSER_GETIDSVALUE2 0X41AC20
  #define CSCRIPTPARSER_GETARGTEXTIDSNAME 0X41AD50

#elif
#endif

#endif //P_SCRCORE_H