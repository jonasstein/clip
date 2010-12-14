#include "core/spacegroup.h"

QList<Spacegroup::SpacegroupSymbolInfo> Spacegroup::static_init() {
  // List of all possible Space group symbols from http://cci.lbl.gov/sginfo/hall_symbols.html
  // plus the following points
  // All centering symbols for  P1 and P-1, e.g. I1
  // Short symbols for monoclinic spacegroups with special axis b, e.g. P2 instead of P121
  // Cubic spacegroups with point groups m3 and m3m without the minus sign on 3, e.g. Pm3m instead of Pm-3m
  // F4/mmm as equivalent to I4/mmm

  QList<SpacegroupSymbolInfo> tmp;
  tmp << SpacegroupSymbolInfo(1, "", "P 1", "", "P 1");
  tmp << SpacegroupSymbolInfo(1, "", "A 1", "", "A 1");
  tmp << SpacegroupSymbolInfo(1, "", "B 1", "", "B 1");
  tmp << SpacegroupSymbolInfo(1, "", "C 1", "", "C 1");
  tmp << SpacegroupSymbolInfo(1, "", "I 1", "", "I 1");
  tmp << SpacegroupSymbolInfo(1, "", "F 1", "", "F 1");

  tmp << SpacegroupSymbolInfo(2, "", "P -1", "", "-P 1");
  tmp << SpacegroupSymbolInfo(2, "", "A -1", "", "-A 1");
  tmp << SpacegroupSymbolInfo(2, "", "B -1", "", "-B 1");
  tmp << SpacegroupSymbolInfo(2, "", "C -1", "", "-C 1");
  tmp << SpacegroupSymbolInfo(2, "", "I -1", "", "-I 1");
  tmp << SpacegroupSymbolInfo(2, "", "F -1", "", "-F 1");

  tmp << SpacegroupSymbolInfo(3, "", "P 2", "", "P 2y");
  tmp << SpacegroupSymbolInfo(3, "b", "P 1 2 1", "", "P 2y");
  tmp << SpacegroupSymbolInfo(3, "c", "P 1 1 2", "", "P 2");
  tmp << SpacegroupSymbolInfo(3, "a", "P 2 1 1", "", "P 2x");

  tmp << SpacegroupSymbolInfo(4, "", "P 21", "", "P 2yb");
  tmp << SpacegroupSymbolInfo(4, "b", "P 1 21 1", "", "P 2yb");
  tmp << SpacegroupSymbolInfo(4, "c", "P 1 1 21", "", "P 2c");
  tmp << SpacegroupSymbolInfo(4, "a", "P 21 1 1", "", "P 2xa");

  tmp << SpacegroupSymbolInfo(5, "", "C 2", "", "C 2y");
  tmp << SpacegroupSymbolInfo(5, "", "A 2", "", "A 2y");
  tmp << SpacegroupSymbolInfo(5, "", "I 2", "", "I 2y");
  tmp << SpacegroupSymbolInfo(5, "b1", "C 1 2 1", "", "C 2y");
  tmp << SpacegroupSymbolInfo(5, "b2", "A 1 2 1", "", "A 2y");
  tmp << SpacegroupSymbolInfo(5, "b3", "I 1 2 1", "", "I 2y");
  tmp << SpacegroupSymbolInfo(5, "c1", "A 1 1 2", "", "A 2");
  tmp << SpacegroupSymbolInfo(5, "c2", "B 1 1 2", "", "B 2");
  tmp << SpacegroupSymbolInfo(5, "c3", "I 1 1 2", "", "I 2");
  tmp << SpacegroupSymbolInfo(5, "a1", "B 2 1 1", "", "B 2x");
  tmp << SpacegroupSymbolInfo(5, "a2", "C 2 1 1", "", "C 2x");
  tmp << SpacegroupSymbolInfo(5, "a3", "I 2 1 1", "", "I 2x");

  tmp << SpacegroupSymbolInfo(6, "", "P m", "", "P -2y");
  tmp << SpacegroupSymbolInfo(6, "b", "P 1 m 1", "", "P -2y");
  tmp << SpacegroupSymbolInfo(6, "c", "P 1 1 m", "", "P -2");
  tmp << SpacegroupSymbolInfo(6, "a", "P m 1 1", "", "P -2x");
  tmp << SpacegroupSymbolInfo(7, "b1", "P 1 c 1", "", "P -2yc");
  tmp << SpacegroupSymbolInfo(7, "b1", "P 1 c 1", "", "P -2yc");
  tmp << SpacegroupSymbolInfo(7, "b1", "P 1 c 1", "", "P -2yc");

  tmp << SpacegroupSymbolInfo(7, "", "P c", "", "P -2yc");
  tmp << SpacegroupSymbolInfo(7, "", "P n", "", "P -2yac");
  tmp << SpacegroupSymbolInfo(7, "", "P a", "", "P -2ya");
  tmp << SpacegroupSymbolInfo(7, "b1", "P 1 c 1", "", "P -2yc");
  tmp << SpacegroupSymbolInfo(7, "b2", "P 1 n 1", "", "P -2yac");
  tmp << SpacegroupSymbolInfo(7, "b3", "P 1 a 1", "", "P -2ya");
  tmp << SpacegroupSymbolInfo(7, "c1", "P 1 1 a", "", "P -2a");
  tmp << SpacegroupSymbolInfo(7, "c2", "P 1 1 n", "", "P -2ab");
  tmp << SpacegroupSymbolInfo(7, "c3", "P 1 1 b", "", "P -2b");
  tmp << SpacegroupSymbolInfo(7, "a1", "P b 1 1", "", "P -2xb");
  tmp << SpacegroupSymbolInfo(7, "a2", "P n 1 1", "", "P -2xbc");
  tmp << SpacegroupSymbolInfo(7, "a3", "P c 1 1", "", "P -2xc");

  tmp << SpacegroupSymbolInfo(8, "", "C m", "", "C -2y");
  tmp << SpacegroupSymbolInfo(8, "", "A m", "", "A -2y");
  tmp << SpacegroupSymbolInfo(8, "", "I m", "", "I -2y");
  tmp << SpacegroupSymbolInfo(8, "b1", "C 1 m 1", "", "C -2y");
  tmp << SpacegroupSymbolInfo(8, "b2", "A 1 m 1", "", "A -2y");
  tmp << SpacegroupSymbolInfo(8, "b3", "I 1 m 1", "", "I -2y");
  tmp << SpacegroupSymbolInfo(8, "c1", "A 1 1 m", "", "A -2");
  tmp << SpacegroupSymbolInfo(8, "c2", "B 1 1 m", "", "B -2");
  tmp << SpacegroupSymbolInfo(8, "c3", "I 1 1 m", "", "I -2");
  tmp << SpacegroupSymbolInfo(8, "a1", "B m 1 1", "", "B -2x");
  tmp << SpacegroupSymbolInfo(8, "a2", "C m 1 1", "", "C -2x");
  tmp << SpacegroupSymbolInfo(8, "a3", "I m 1 1", "", "I -2x");

  tmp << SpacegroupSymbolInfo(9, "", "C c", "", "C -2yc");
  tmp << SpacegroupSymbolInfo(9, "", "A n", "", "A -2yac");
  tmp << SpacegroupSymbolInfo(9, "", "I a", "", "I -2ya");
  tmp << SpacegroupSymbolInfo(9, "b1", "C 1 c 1", "", "C -2yc");
  tmp << SpacegroupSymbolInfo(9, "b2", "A 1 n 1", "", "A -2yac");
  tmp << SpacegroupSymbolInfo(9, "b3", "I 1 a 1", "", "I -2ya");
  tmp << SpacegroupSymbolInfo(9, "-b1", "A 1 a 1", "", "A -2ya");
  tmp << SpacegroupSymbolInfo(9, "-b2", "C 1 n 1", "", "C -2ybc");
  tmp << SpacegroupSymbolInfo(9, "-b3", "I 1 c 1", "", "I -2yc");
  tmp << SpacegroupSymbolInfo(9, "c1", "A 1 1 a", "", "A -2a");
  tmp << SpacegroupSymbolInfo(9, "c2", "B 1 1 n", "", "B -2bc");
  tmp << SpacegroupSymbolInfo(9, "c3", "I 1 1 b", "", "I -2b");
  tmp << SpacegroupSymbolInfo(9, "-c1", "B 1 1 b", "", "B -2b");
  tmp << SpacegroupSymbolInfo(9, "-c2", "A 1 1 n", "", "A -2ac");
  tmp << SpacegroupSymbolInfo(9, "-c3", "I 1 1 a", "", "I -2a");
  tmp << SpacegroupSymbolInfo(9, "a1", "B b 1 1", "", "B -2xb");
  tmp << SpacegroupSymbolInfo(9, "a2", "C n 1 1", "", "C -2xbc");
  tmp << SpacegroupSymbolInfo(9, "a3", "I c 1 1", "", "I -2xc");
  tmp << SpacegroupSymbolInfo(9, "-a1", "C c 1 1", "", "C -2xc");
  tmp << SpacegroupSymbolInfo(9, "-a2", "B n 1 1", "", "B -2xbc");
  tmp << SpacegroupSymbolInfo(9, "-a3", "I b 1 1", "", "I -2xb");

  tmp << SpacegroupSymbolInfo(10, "", "P 2/m", "", "-P 2y");
  tmp << SpacegroupSymbolInfo(10, "b", "P 1 2/m 1", "", "-P 2y");
  tmp << SpacegroupSymbolInfo(10, "c", "P 1 1 2/m", "", "-P 2");
  tmp << SpacegroupSymbolInfo(10, "a", "P 2/m 1 1", "", "-P 2x");

  tmp << SpacegroupSymbolInfo(11, "", "P 21/m", "", "-P 2yb");
  tmp << SpacegroupSymbolInfo(11, "b", "P 1 21/m 1", "", "-P 2yb");
  tmp << SpacegroupSymbolInfo(11, "c", "P 1 1 21/m", "", "-P 2c");
  tmp << SpacegroupSymbolInfo(11, "a", "P 21/m 1 1", "", "-P 2xa");

  tmp << SpacegroupSymbolInfo(12, "", "C 2/m", "", "-C 2y");
  tmp << SpacegroupSymbolInfo(12, "", "A 2/m", "", "-A 2y");
  tmp << SpacegroupSymbolInfo(12, "", "I 2/m", "", "-I 2y");
  tmp << SpacegroupSymbolInfo(12, "b1", "C 1 2/m 1", "", "-C 2y");
  tmp << SpacegroupSymbolInfo(12, "b2", "A 1 2/m 1", "", "-A 2y");
  tmp << SpacegroupSymbolInfo(12, "b3", "I 1 2/m 1", "", "-I 2y");
  tmp << SpacegroupSymbolInfo(12, "c1", "A 1 1 2/m", "", "-A 2");
  tmp << SpacegroupSymbolInfo(12, "c2", "B 1 1 2/m", "", "-B 2");
  tmp << SpacegroupSymbolInfo(12, "c3", "I 1 1 2/m", "", "-I 2");
  tmp << SpacegroupSymbolInfo(12, "a1", "B 2/m 1 1", "", "-B 2x");
  tmp << SpacegroupSymbolInfo(12, "a2", "C 2/m 1 1", "", "-C 2x");
  tmp << SpacegroupSymbolInfo(12, "a3", "I 2/m 1 1", "", "-I 2x");

  tmp << SpacegroupSymbolInfo(13, "", "P 2/c", "", "-P 2yc");
  tmp << SpacegroupSymbolInfo(13, "", "P 2/n", "", "-P 2yac");
  tmp << SpacegroupSymbolInfo(13, "", "P 2/a", "", "-P 2ya");
  tmp << SpacegroupSymbolInfo(13, "b1", "P 1 2/c 1", "", "-P 2yc");
  tmp << SpacegroupSymbolInfo(13, "b2", "P 1 2/n 1", "", "-P 2yac");
  tmp << SpacegroupSymbolInfo(13, "b3", "P 1 2/a 1", "", "-P 2ya");
  tmp << SpacegroupSymbolInfo(13, "c1", "P 1 1 2/a", "", "-P 2a");
  tmp << SpacegroupSymbolInfo(13, "c2", "P 1 1 2/n", "", "-P 2ab");
  tmp << SpacegroupSymbolInfo(13, "c3", "P 1 1 2/b", "", "-P 2b");
  tmp << SpacegroupSymbolInfo(13, "a1", "P 2/b 1 1", "", "-P 2xb");
  tmp << SpacegroupSymbolInfo(13, "a2", "P 2/n 1 1", "", "-P 2xbc");
  tmp << SpacegroupSymbolInfo(13, "a3", "P 2/c 1 1", "", "-P 2xc");

  tmp << SpacegroupSymbolInfo(14, "", "P 21/c", "", "-P 2ybc");
  tmp << SpacegroupSymbolInfo(14, "", "P 21/n", "", "-P 2yn");
  tmp << SpacegroupSymbolInfo(14, "", "P 21/a", "", "-P 2yab");
  tmp << SpacegroupSymbolInfo(14, "b1", "P 1 21/c 1", "", "-P 2ybc");
  tmp << SpacegroupSymbolInfo(14, "b2", "P 1 21/n 1", "", "-P 2yn");
  tmp << SpacegroupSymbolInfo(14, "b3", "P 1 21/a 1", "", "-P 2yab");
  tmp << SpacegroupSymbolInfo(14, "c1", "P 1 1 21/a", "", "-P 2ac");
  tmp << SpacegroupSymbolInfo(14, "c2", "P 1 1 21/n", "", "-P 2n");
  tmp << SpacegroupSymbolInfo(14, "c3", "P 1 1 21/b", "", "-P 2bc");
  tmp << SpacegroupSymbolInfo(14, "a1", "P 21/b 1 1", "", "-P 2xab");
  tmp << SpacegroupSymbolInfo(14, "a2", "P 21/n 1 1", "", "-P 2xn");
  tmp << SpacegroupSymbolInfo(14, "a3", "P 21/c 1 1", "", "-P 2xac");

  tmp << SpacegroupSymbolInfo(15, "", "C 2/c", "", "-C 2yc");
  tmp << SpacegroupSymbolInfo(15, "", "A 2/n", "", "-A 2yac");
  tmp << SpacegroupSymbolInfo(15, "", "I 2/a", "", "-I 2ya");
  tmp << SpacegroupSymbolInfo(15, "b1", "C 1 2/c 1", "", "-C 2yc");
  tmp << SpacegroupSymbolInfo(15, "b2", "A 1 2/n 1", "", "-A 2yac");
  tmp << SpacegroupSymbolInfo(15, "b3", "I 1 2/a 1", "", "-I 2ya");
  tmp << SpacegroupSymbolInfo(15, "-b1", "A 1 2/a 1", "", "-A 2ya");
  tmp << SpacegroupSymbolInfo(15, "-b2", "C 1 2/n 1", "", "-C 2ybc");
  tmp << SpacegroupSymbolInfo(15, "-b3", "I 1 2/c 1", "", "-I 2yc");
  tmp << SpacegroupSymbolInfo(15, "c1", "A 1 1 2/a", "", "-A 2a");
  tmp << SpacegroupSymbolInfo(15, "c2", "B 1 1 2/n", "", "-B 2bc");
  tmp << SpacegroupSymbolInfo(15, "c3", "I 1 1 2/b", "", "-I 2b");
  tmp << SpacegroupSymbolInfo(15, "-c1", "B 1 1 2/b", "", "-B 2b");
  tmp << SpacegroupSymbolInfo(15, "-c2", "A 1 1 2/n", "", "-A 2ac");
  tmp << SpacegroupSymbolInfo(15, "-c3", "I 1 1 2/a", "", "-I 2a");
  tmp << SpacegroupSymbolInfo(15, "a1", "B 2/b 1 1", "", "-B 2xb");
  tmp << SpacegroupSymbolInfo(15, "a2", "C 2/n 1 1", "", "-C 2xbc");
  tmp << SpacegroupSymbolInfo(15, "a3", "I 2/c 1 1", "", "-I 2xc");
  tmp << SpacegroupSymbolInfo(15, "-a1", "C 2/c 1 1", "", "-C 2xc");
  tmp << SpacegroupSymbolInfo(15, "-a2", "B 2/n 1 1", "", "-B 2xbc");
  tmp << SpacegroupSymbolInfo(15, "-a3", "I 2/b 1 1", "", "-I 2xb");

  tmp << SpacegroupSymbolInfo(16, "", "P 2 2 2", "", "P 2 2");

  tmp << SpacegroupSymbolInfo(17, "", "P 2 2 21", "", "P 2c 2");
  tmp << SpacegroupSymbolInfo(17, "cab", "P 21 2 2", "", "P 2a 2a");
  tmp << SpacegroupSymbolInfo(17, "bca", "P 2 21 2", "", "P 2 2b");

  tmp << SpacegroupSymbolInfo(18, "", "P 21 21 2", "", "P 2 2ab");
  tmp << SpacegroupSymbolInfo(18, "cab", "P 2 21 21", "", "P 2bc 2");
  tmp << SpacegroupSymbolInfo(18, "bca", "P 21 2 21", "", "P 2ac 2ac");

  tmp << SpacegroupSymbolInfo(19, "", "P 21 21 21", "", "P 2ac 2ab");

  tmp << SpacegroupSymbolInfo(20, "", "C 2 2 21", "", "C 2c 2");
  tmp << SpacegroupSymbolInfo(20, "cab", "A 21 2 2", "", "A 2a 2a");
  tmp << SpacegroupSymbolInfo(20, "bca", "B 2 21 2", "", "B 2 2b");

  tmp << SpacegroupSymbolInfo(21, "", "C 2 2 2", "", "C 2 2");
  tmp << SpacegroupSymbolInfo(21, "cab", "A 2 2 2", "", "A 2 2");
  tmp << SpacegroupSymbolInfo(21, "bca", "B 2 2 2", "", "B 2 2");

  tmp << SpacegroupSymbolInfo(22, "", "F 2 2 2", "", "F 2 2");

  tmp << SpacegroupSymbolInfo(23, "", "I 2 2 2", "", "I 2 2");

  tmp << SpacegroupSymbolInfo(24, "", "I 21 21 21", "", "I 2b 2c");

  tmp << SpacegroupSymbolInfo(25, "", "P m m 2", "", "P 2 -2");
  tmp << SpacegroupSymbolInfo(25, "cab", "P 2 m m", "", "P -2 2");
  tmp << SpacegroupSymbolInfo(25, "bca", "P m 2 m", "", "P -2 -2");

  tmp << SpacegroupSymbolInfo(26, "", "P m c 21", "", "P 2c -2");
  tmp << SpacegroupSymbolInfo(26, "ba-c", "P c m 21", "", "P 2c -2c");
  tmp << SpacegroupSymbolInfo(26, "cab", "P 21 m a", "", "P -2a 2a");
  tmp << SpacegroupSymbolInfo(26, "-cba", "P 21 a m", "", "P -2 2a");
  tmp << SpacegroupSymbolInfo(26, "bca", "P b 21 m", "", "P -2 -2b");
  tmp << SpacegroupSymbolInfo(26, "a-cb", "P m 21 b", "", "P -2b -2");

  tmp << SpacegroupSymbolInfo(27, "", "P c c 2", "", "P 2 -2c");
  tmp << SpacegroupSymbolInfo(27, "cab", "P 2 a a", "", "P -2a 2");
  tmp << SpacegroupSymbolInfo(27, "bca", "P b 2 b", "", "P -2b -2b");

  tmp << SpacegroupSymbolInfo(28, "", "P m a 2", "", "P 2 -2a");
  tmp << SpacegroupSymbolInfo(28, "ba-c", "P b m 2", "", "P 2 -2b");
  tmp << SpacegroupSymbolInfo(28, "cab", "P 2 m b", "", "P -2b 2");
  tmp << SpacegroupSymbolInfo(28, "-cba", "P 2 c m", "", "P -2c 2");
  tmp << SpacegroupSymbolInfo(28, "bca", "P c 2 m", "", "P -2c -2c");
  tmp << SpacegroupSymbolInfo(28, "a-cb", "P m 2 a", "", "P -2a -2a");

  tmp << SpacegroupSymbolInfo(29, "", "P c a 21", "", "P 2c -2ac");
  tmp << SpacegroupSymbolInfo(29, "ba-c", "P b c 21", "", "P 2c -2b");
  tmp << SpacegroupSymbolInfo(29, "cab", "P 21 a b", "", "P -2b 2a");
  tmp << SpacegroupSymbolInfo(29, "-cba", "P 21 c a", "", "P -2ac 2a");
  tmp << SpacegroupSymbolInfo(29, "bca", "P c 21 b", "", "P -2bc -2c");
  tmp << SpacegroupSymbolInfo(29, "a-cb", "P b 21 a", "", "P -2a -2ab");

  tmp << SpacegroupSymbolInfo(30, "", "P n c 2", "", "P 2 -2bc");
  tmp << SpacegroupSymbolInfo(30, "ba-c", "P c n 2", "", "P 2 -2ac");
  tmp << SpacegroupSymbolInfo(30, "cab", "P 2 n a", "", "P -2ac 2");
  tmp << SpacegroupSymbolInfo(30, "-cba", "P 2 a n", "", "P -2ab 2");
  tmp << SpacegroupSymbolInfo(30, "bca", "P b 2 n", "", "P -2ab -2ab");
  tmp << SpacegroupSymbolInfo(30, "a-cb", "P n 2 b", "", "P -2bc -2bc");

  tmp << SpacegroupSymbolInfo(31, "", "P m n 21", "", "P 2ac -2");
  tmp << SpacegroupSymbolInfo(31, "ba-c", "P n m 21", "", "P 2bc -2bc");
  tmp << SpacegroupSymbolInfo(31, "cab", "P 21 m n", "", "P -2ab 2ab");
  tmp << SpacegroupSymbolInfo(31, "-cba", "P 21 n m", "", "P -2 2ac");
  tmp << SpacegroupSymbolInfo(31, "bca", "P n 21 m", "", "P -2 -2bc");
  tmp << SpacegroupSymbolInfo(31, "a-cb", "P m 21 n", "", "P -2ab -2");

  tmp << SpacegroupSymbolInfo(32, "", "P b a 2", "", "P 2 -2ab");
  tmp << SpacegroupSymbolInfo(32, "cab", "P 2 c b", "", "P -2bc 2");
  tmp << SpacegroupSymbolInfo(32, "bca", "P c 2 a", "", "P -2ac -2ac");

  tmp << SpacegroupSymbolInfo(33, "", "P n a 21", "", "P 2c -2n");
  tmp << SpacegroupSymbolInfo(33, "ba-c", "P b n 21", "", "P 2c -2ab");
  tmp << SpacegroupSymbolInfo(33, "cab", "P 21 n b", "", "P -2bc 2a");
  tmp << SpacegroupSymbolInfo(33, "-cba", "P 21 c n", "", "P -2n 2a");
  tmp << SpacegroupSymbolInfo(33, "bca", "P c 21 n", "", "P -2n -2ac");
  tmp << SpacegroupSymbolInfo(33, "a-cb", "P n 21 a", "", "P -2ac -2n");

  tmp << SpacegroupSymbolInfo(34, "", "P n n 2", "", "P 2 -2n");
  tmp << SpacegroupSymbolInfo(34, "cab", "P 2 n n", "", "P -2n 2");
  tmp << SpacegroupSymbolInfo(34, "bca", "P n 2 n", "", "P -2n -2n");

  tmp << SpacegroupSymbolInfo(35, "", "C m m 2", "", "C 2 -2");
  tmp << SpacegroupSymbolInfo(35, "cab", "A 2 m m", "", "A -2 2");
  tmp << SpacegroupSymbolInfo(35, "bca", "B m 2 m", "", "B -2 -2");

  tmp << SpacegroupSymbolInfo(36, "", "C m c 21", "", "C 2c -2");
  tmp << SpacegroupSymbolInfo(36, "ba-c", "C c m 21", "", "C 2c -2c");
  tmp << SpacegroupSymbolInfo(36, "cab", "A 21 m a", "", "A -2a 2a");
  tmp << SpacegroupSymbolInfo(36, "-cba", "A 21 a m", "", "A -2 2a");
  tmp << SpacegroupSymbolInfo(36, "bca", "B b 21 m", "", "B -2 -2b");
  tmp << SpacegroupSymbolInfo(36, "a-cb", "B m 21 b", "", "B -2b -2");

  tmp << SpacegroupSymbolInfo(37, "", "C c c 2", "", "C 2 -2c");
  tmp << SpacegroupSymbolInfo(37, "cab", "A 2 a a", "", "A -2a 2");
  tmp << SpacegroupSymbolInfo(37, "bca", "B b 2 b", "", "B -2b -2b");

  tmp << SpacegroupSymbolInfo(38, "", "A m m 2", "", "A 2 -2");
  tmp << SpacegroupSymbolInfo(38, "ba-c", "B m m 2", "", "B 2 -2");
  tmp << SpacegroupSymbolInfo(38, "cab", "B 2 m m", "", "B -2 2");
  tmp << SpacegroupSymbolInfo(38, "-cba", "C 2 m m", "", "C -2 2");
  tmp << SpacegroupSymbolInfo(38, "bca", "C m 2 m", "", "C -2 -2");
  tmp << SpacegroupSymbolInfo(38, "a-cb", "A m 2 m", "", "A -2 -2");

  tmp << SpacegroupSymbolInfo(39, "", "A b m 2", "", "A 2 -2c");
  tmp << SpacegroupSymbolInfo(39, "ba-c", "B m a 2", "", "B 2 -2c");
  tmp << SpacegroupSymbolInfo(39, "cab", "B 2 c m", "", "B -2c 2");
  tmp << SpacegroupSymbolInfo(39, "-cba", "C 2 m b", "", "C -2b 2");
  tmp << SpacegroupSymbolInfo(39, "bca", "C m 2 a", "", "C -2b -2b");
  tmp << SpacegroupSymbolInfo(39, "a-cb", "A c 2 m", "", "A -2c -2c");

  tmp << SpacegroupSymbolInfo(40, "", "A m a 2", "", "A 2 -2a");
  tmp << SpacegroupSymbolInfo(40, "ba-c", "B b m 2", "", "B 2 -2b");
  tmp << SpacegroupSymbolInfo(40, "cab", "B 2 m b", "", "B -2b 2");
  tmp << SpacegroupSymbolInfo(40, "-cba", "C 2 c m", "", "C -2c 2");
  tmp << SpacegroupSymbolInfo(40, "bca", "C c 2 m", "", "C -2c -2c");
  tmp << SpacegroupSymbolInfo(40, "a-cb", "A m 2 a", "", "A -2a -2a");

  tmp << SpacegroupSymbolInfo(41, "", "A b a 2", "", "A 2 -2ac");
  tmp << SpacegroupSymbolInfo(41, "ba-c", "B b a 2", "", "B 2 -2bc");
  tmp << SpacegroupSymbolInfo(41, "cab", "B 2 c b", "", "B -2bc 2");
  tmp << SpacegroupSymbolInfo(41, "-cba", "C 2 c b", "", "C -2bc 2");
  tmp << SpacegroupSymbolInfo(41, "bca", "C c 2 a", "", "C -2bc -2bc");
  tmp << SpacegroupSymbolInfo(41, "a-cb", "A c 2 a", "", "A -2ac -2ac");

  tmp << SpacegroupSymbolInfo(42, "", "F m m 2", "", "F 2 -2");
  tmp << SpacegroupSymbolInfo(42, "cab", "F 2 m m", "", "F -2 2");
  tmp << SpacegroupSymbolInfo(42, "bca", "F m 2 m", "", "F -2 -2");

  tmp << SpacegroupSymbolInfo(43, "", "F d d 2", "", "F 2 -2d");
  tmp << SpacegroupSymbolInfo(43, "cab", "F 2 d d", "", "F -2d 2");
  tmp << SpacegroupSymbolInfo(43, "bca", "F d 2 d", "", "F -2d -2d");

  tmp << SpacegroupSymbolInfo(44, "", "I m m 2", "", "I 2 -2");
  tmp << SpacegroupSymbolInfo(44, "cab", "I 2 m m", "", "I -2 2");
  tmp << SpacegroupSymbolInfo(44, "bca", "I m 2 m", "", "I -2 -2");

  tmp << SpacegroupSymbolInfo(45, "", "I b a 2", "", "I 2 -2c");
  tmp << SpacegroupSymbolInfo(45, "cab", "I 2 c b", "", "I -2a 2");
  tmp << SpacegroupSymbolInfo(45, "bca", "I c 2 a", "", "I -2b -2b");

  tmp << SpacegroupSymbolInfo(46, "", "I m a 2", "", "I 2 -2a");
  tmp << SpacegroupSymbolInfo(46, "ba-c", "I b m 2", "", "I 2 -2b");
  tmp << SpacegroupSymbolInfo(46, "cab", "I 2 m b", "", "I -2b 2");
  tmp << SpacegroupSymbolInfo(46, "-cba", "I 2 c m", "", "I -2c 2");
  tmp << SpacegroupSymbolInfo(46, "bca", "I c 2 m", "", "I -2c -2c");
  tmp << SpacegroupSymbolInfo(46, "a-cb", "I m 2 a", "", "I -2a -2a");

  tmp << SpacegroupSymbolInfo(47, "", "P m m m", "", "-P 2 2");

  tmp << SpacegroupSymbolInfo(48, "1", "P n n n", "1", "P 2 2 -1n");
  tmp << SpacegroupSymbolInfo(48, "2", "P n n n", "2", "-P 2ab 2bc");

  tmp << SpacegroupSymbolInfo(49, "", "P c c m", "", "-P 2 2c");
  tmp << SpacegroupSymbolInfo(49, "cab", "P m a a", "", "-P 2a 2");
  tmp << SpacegroupSymbolInfo(49, "bca", "P b m b", "", "-P 2b 2b");

  tmp << SpacegroupSymbolInfo(50, "1", "P b a n", "1", "P 2 2 -1ab");
  tmp << SpacegroupSymbolInfo(50, "2", "P b a n", "2", "-P 2ab 2b");
  tmp << SpacegroupSymbolInfo(50, "1cab", "P n c b", "1", "P 2 2 -1bc");
  tmp << SpacegroupSymbolInfo(50, "2cab", "P n c b", "2", "-P 2b 2bc");
  tmp << SpacegroupSymbolInfo(50, "1bca", "P c n a", "1", "P 2 2 -1ac");
  tmp << SpacegroupSymbolInfo(50, "2bca", "P c n a", "2", "-P 2a 2c");

  tmp << SpacegroupSymbolInfo(51, "", "P m m a", "", "-P 2a 2a");
  tmp << SpacegroupSymbolInfo(51, "ba-c", "P m m b", "", "-P 2b 2");
  tmp << SpacegroupSymbolInfo(51, "cab", "P b m m", "", "-P 2 2b");
  tmp << SpacegroupSymbolInfo(51, "-cba", "P c m m", "", "-P 2c 2c");
  tmp << SpacegroupSymbolInfo(51, "bca", "P m c m", "", "-P 2c 2");
  tmp << SpacegroupSymbolInfo(51, "a-cb", "P m a m", "", "-P 2 2a");

  tmp << SpacegroupSymbolInfo(52, "", "P n n a", "", "-P 2a 2bc");
  tmp << SpacegroupSymbolInfo(52, "ba-c", "P n n b", "", "-P 2b 2n");
  tmp << SpacegroupSymbolInfo(52, "cab", "P b n n", "", "-P 2n 2b");
  tmp << SpacegroupSymbolInfo(52, "-cba", "P c n n", "", "-P 2ab 2c");
  tmp << SpacegroupSymbolInfo(52, "bca", "P n c n", "", "-P 2ab 2n");
  tmp << SpacegroupSymbolInfo(52, "a-cb", "P n a n", "", "-P 2n 2bc");

  tmp << SpacegroupSymbolInfo(53, "", "P m n a", "", "-P 2ac 2");
  tmp << SpacegroupSymbolInfo(53, "ba-c", "P n m b", "", "-P 2bc 2bc");
  tmp << SpacegroupSymbolInfo(53, "cab", "P b m n", "", "-P 2ab 2ab");
  tmp << SpacegroupSymbolInfo(53, "-cba", "P c n m", "", "-P 2 2ac");
  tmp << SpacegroupSymbolInfo(53, "bca", "P n c m", "", "-P 2 2bc");
  tmp << SpacegroupSymbolInfo(53, "a-cb", "P m a n", "", "-P 2ab 2");

  tmp << SpacegroupSymbolInfo(54, "", "P c c a", "", "-P 2a 2ac");
  tmp << SpacegroupSymbolInfo(54, "ba-c", "P c c b", "", "-P 2b 2c");
  tmp << SpacegroupSymbolInfo(54, "cab", "P b a a", "", "-P 2a 2b");
  tmp << SpacegroupSymbolInfo(54, "-cba", "P c a a", "", "-P 2ac 2c");
  tmp << SpacegroupSymbolInfo(54, "bca", "P b c b", "", "-P 2bc 2b");
  tmp << SpacegroupSymbolInfo(54, "a-cb", "P b a b", "", "-P 2b 2ab");

  tmp << SpacegroupSymbolInfo(55, "", "P b a m", "", "-P 2 2ab");
  tmp << SpacegroupSymbolInfo(55, "cab", "P m c b", "", "-P 2bc 2");
  tmp << SpacegroupSymbolInfo(55, "bca", "P c m a", "", "-P 2ac 2ac");
  tmp << SpacegroupSymbolInfo(56, "", "P c c n", "", "-P 2ab 2ac");
  tmp << SpacegroupSymbolInfo(56, "cab", "P n a a", "", "-P 2ac 2bc");
  tmp << SpacegroupSymbolInfo(56, "bca", "P b n b", "", "-P 2bc 2ab");

  tmp << SpacegroupSymbolInfo(57, "", "P b c m", "", "-P 2c 2b");
  tmp << SpacegroupSymbolInfo(57, "ba-c", "P c a m", "", "-P 2c 2ac");
  tmp << SpacegroupSymbolInfo(57, "cab", "P m c a", "", "-P 2ac 2a");
  tmp << SpacegroupSymbolInfo(57, "-cba", "P m a b", "", "-P 2b 2a");
  tmp << SpacegroupSymbolInfo(57, "bca", "P b m a", "", "-P 2a 2ab");
  tmp << SpacegroupSymbolInfo(57, "a-cb", "P c m b", "", "-P 2bc 2c");

  tmp << SpacegroupSymbolInfo(58, "", "P n n m", "", "-P 2 2n");
  tmp << SpacegroupSymbolInfo(58, "cab", "P m n n", "", "-P 2n 2");
  tmp << SpacegroupSymbolInfo(58, "bca", "P n m n", "", "-P 2n 2n");

  tmp << SpacegroupSymbolInfo(59, "1", "P m m n", "1", "P 2 2ab -1ab");
  tmp << SpacegroupSymbolInfo(59, "2", "P m m n", "2", "-P 2ab 2a");
  tmp << SpacegroupSymbolInfo(59, "1cab", "P n m m", "1", "P 2bc 2 -1bc");
  tmp << SpacegroupSymbolInfo(59, "2cab", "P n m m", "2", "-P 2c 2bc");
  tmp << SpacegroupSymbolInfo(59, "1bca", "P m n m", "1", "P 2ac 2ac -1ac");
  tmp << SpacegroupSymbolInfo(59, "2bca", "P m n m", "2", "-P 2c 2a");

  tmp << SpacegroupSymbolInfo(60, "", "P b c n", "", "-P 2n 2ab");
  tmp << SpacegroupSymbolInfo(60, "ba-c", "P c a n", "", "-P 2n 2c");
  tmp << SpacegroupSymbolInfo(60, "cab", "P n c a", "", "-P 2a 2n");
  tmp << SpacegroupSymbolInfo(60, "-cba", "P n a b", "", "-P 2bc 2n");
  tmp << SpacegroupSymbolInfo(60, "bca", "P b n a", "", "-P 2ac 2b");
  tmp << SpacegroupSymbolInfo(60, "a-cb", "P c n b", "", "-P 2b 2ac");

  tmp << SpacegroupSymbolInfo(61, "", "P b c a", "", "-P 2ac 2ab");
  tmp << SpacegroupSymbolInfo(61, "ba-c", "P c a b", "", "-P 2bc 2ac");

  tmp << SpacegroupSymbolInfo(62, "", "P n m a", "", "-P 2ac 2n");
  tmp << SpacegroupSymbolInfo(62, "ba-c", "P m n b", "", "-P 2bc 2a");
  tmp << SpacegroupSymbolInfo(62, "cab", "P b n m", "", "-P 2c 2ab");
  tmp << SpacegroupSymbolInfo(62, "-cba", "P c m n", "", "-P 2n 2ac");
  tmp << SpacegroupSymbolInfo(62, "bca", "P m c n", "", "-P 2n 2a");
  tmp << SpacegroupSymbolInfo(62, "a-cb", "P n a m", "", "-P 2c 2n");

  tmp << SpacegroupSymbolInfo(63, "", "C m c m", "", "-C 2c 2");
  tmp << SpacegroupSymbolInfo(63, "ba-c", "C c m m", "", "-C 2c 2c");
  tmp << SpacegroupSymbolInfo(63, "cab", "A m m a", "", "-A 2a 2a");
  tmp << SpacegroupSymbolInfo(63, "-cba", "A m a m", "", "-A 2 2a");
  tmp << SpacegroupSymbolInfo(63, "bca", "B b m m", "", "-B 2 2b");
  tmp << SpacegroupSymbolInfo(63, "a-cb", "B m m b", "", "-B 2b 2");

  tmp << SpacegroupSymbolInfo(64, "", "C m c a", "", "-C 2bc 2");
  tmp << SpacegroupSymbolInfo(64, "ba-c", "C c m b", "", "-C 2bc 2bc");
  tmp << SpacegroupSymbolInfo(64, "cab", "A b m a", "", "-A 2ac 2ac");
  tmp << SpacegroupSymbolInfo(64, "-cba", "A c a m", "", "-A 2 2ac");
  tmp << SpacegroupSymbolInfo(64, "bca", "B b c m", "", "-B 2 2bc");
  tmp << SpacegroupSymbolInfo(64, "a-cb", "B m a b", "", "-B 2bc 2");

  tmp << SpacegroupSymbolInfo(65, "", "C m m m", "", "-C 2 2");
  tmp << SpacegroupSymbolInfo(65, "cab", "A m m m", "", "-A 2 2");
  tmp << SpacegroupSymbolInfo(65, "bca", "B m m m", "", "-B 2 2");

  tmp << SpacegroupSymbolInfo(66, "", "C c c m", "", "-C 2 2c");
  tmp << SpacegroupSymbolInfo(66, "cab", "A m a a", "", "-A 2a 2");
  tmp << SpacegroupSymbolInfo(66, "bca", "B b m b", "", "-B 2b 2b");

  tmp << SpacegroupSymbolInfo(67, "", "C m m a", "", "-C 2b 2");
  tmp << SpacegroupSymbolInfo(67, "ba-c", "C m m b", "", "-C 2b 2b");
  tmp << SpacegroupSymbolInfo(67, "cab", "A b m m", "", "-A 2c 2c");
  tmp << SpacegroupSymbolInfo(67, "-cba", "A c m m", "", "-A 2 2c");
  tmp << SpacegroupSymbolInfo(67, "bca", "B m c m", "", "-B 2 2c");
  tmp << SpacegroupSymbolInfo(67, "a-cb", "B m a m", "", "-B 2c 2");

  tmp << SpacegroupSymbolInfo(68, "1", "C c c a", "1", "C 2 2 -1bc");
  tmp << SpacegroupSymbolInfo(68, "2", "C c c a", "2", "-C 2b 2bc");
  tmp << SpacegroupSymbolInfo(68, "1ba-c", "C c c b", "1", "C 2 2 -1bc");
  tmp << SpacegroupSymbolInfo(68, "2ba-c", "C c c b", "2", "-C 2b 2c");
  tmp << SpacegroupSymbolInfo(68, "1cab", "A b a a", "1", "A 2 2 -1ac");
  tmp << SpacegroupSymbolInfo(68, "2cab", "A b a a", "2", "-A 2a 2c");
  tmp << SpacegroupSymbolInfo(68, "1-cba", "A c a a", "1", "A 2 2 -1ac");
  tmp << SpacegroupSymbolInfo(68, "2-cba", "A c a a", "2", "-A 2ac 2c");
  tmp << SpacegroupSymbolInfo(68, "1bca", "B b c b", "1", "B 2 2 -1bc");
  tmp << SpacegroupSymbolInfo(68, "2bca", "B b c b", "2", "-B 2bc 2b");
  tmp << SpacegroupSymbolInfo(68, "1a-cb", "B b a b", "1", "B 2 2 -1bc");
  tmp << SpacegroupSymbolInfo(68, "2a-cb", "B b a b", "2", "-B 2b 2bc");

  tmp << SpacegroupSymbolInfo(69, "", "F m m m", "", "-F 2 2");

  tmp << SpacegroupSymbolInfo(70, "1", "F d d d", "1", "F 2 2 -1d");
  tmp << SpacegroupSymbolInfo(70, "2", "F d d d", "2", "-F 2uv 2vw");

  tmp << SpacegroupSymbolInfo(71, "", "I m m m", "", "-I 2 2");

  tmp << SpacegroupSymbolInfo(72, "", "I b a m", "", "-I 2 2c");
  tmp << SpacegroupSymbolInfo(72, "cab", "I m c b", "", "-I 2a 2");
  tmp << SpacegroupSymbolInfo(72, "bca", "I c m a", "", "-I 2b 2b");

  tmp << SpacegroupSymbolInfo(73, "", "I b c a", "", "-I 2b 2c");
  tmp << SpacegroupSymbolInfo(73, "ba-c", "I c a b", "", "-I 2a 2b");

  tmp << SpacegroupSymbolInfo(74, "", "I m m a", "", "-I 2b 2");
  tmp << SpacegroupSymbolInfo(74, "ba-c", "I m m b", "", "-I 2a 2a");
  tmp << SpacegroupSymbolInfo(74, "cab", "I b m m", "", "-I 2c 2c");
  tmp << SpacegroupSymbolInfo(74, "-cba", "I c m m", "", "-I 2 2b");
  tmp << SpacegroupSymbolInfo(74, "bca", "I m c m", "", "-I 2 2a");
  tmp << SpacegroupSymbolInfo(74, "a-cb", "I m a m", "", "-I 2c 2");

  tmp << SpacegroupSymbolInfo(75, "", "P 4", "", "P 4");

  tmp << SpacegroupSymbolInfo(76, "", "P 41", "", "P 4w");

  tmp << SpacegroupSymbolInfo(77, "", "P 42", "", "P 4c");

  tmp << SpacegroupSymbolInfo(78, "", "P 43", "", "P 4cw");

  tmp << SpacegroupSymbolInfo(79, "", "I 4", "", "I 4");

  tmp << SpacegroupSymbolInfo(80, "", "I 41", "", "I 4bw");

  tmp << SpacegroupSymbolInfo(81, "", "P -4", "", "P -4");

  tmp << SpacegroupSymbolInfo(82, "", "I -4", "", "I -4");

  tmp << SpacegroupSymbolInfo(83, "", "P 4/m", "", "-P 4");

  tmp << SpacegroupSymbolInfo(84, "", "P 42/m", "", "-P 4c");

  tmp << SpacegroupSymbolInfo(85, "1", "P 4/n", "1", "P 4ab -1ab");
  tmp << SpacegroupSymbolInfo(85, "2", "P 4/n", "2", "-P 4a");

  tmp << SpacegroupSymbolInfo(86, "1", "P 42/n", "1", "P 4n -1n");
  tmp << SpacegroupSymbolInfo(86, "2", "P 42/n", "2", "-P 4bc");

  tmp << SpacegroupSymbolInfo(87, "", "I 4/m", "", "-I 4");

  tmp << SpacegroupSymbolInfo(88, "1", "I 41/a", "1", "I 4bw -1bw");
  tmp << SpacegroupSymbolInfo(88, "2", "I 41/a", "2", "-I 4ad");

  tmp << SpacegroupSymbolInfo(89, "", "P 4 2 2", "", "P 4 2");

  tmp << SpacegroupSymbolInfo(90, "", "P 42 1 2", "", "P 4ab 2ab");

  tmp << SpacegroupSymbolInfo(91, "", "P 41 2 2", "", "P 4w 2c");

  tmp << SpacegroupSymbolInfo(92, "", "P 41 21 2", "", "P 4abw 2nw");

  tmp << SpacegroupSymbolInfo(93, "", "P 42 2 2", "", "P 4c 2");

  tmp << SpacegroupSymbolInfo(94, "", "P 42 21 2", "", "P 4n 2n");

  tmp << SpacegroupSymbolInfo(95, "", "P 43 2 2", "", "P 4cw 2c");

  tmp << SpacegroupSymbolInfo(96, "", "P 43 21 2", "", "P 4nw 2abw");

  tmp << SpacegroupSymbolInfo(97, "", "I 4 2 2", "", "I 4 2");

  tmp << SpacegroupSymbolInfo(98, "", "I 41 2 2", "", "I 4bw 2bw");

  tmp << SpacegroupSymbolInfo(99, "", "P 4 m m", "", "P 4 -2");

  tmp << SpacegroupSymbolInfo(100, "", "P 4 b m", "", "P 4 -2ab");

  tmp << SpacegroupSymbolInfo(101, "", "P 42 c m", "", "P 4c -2c");

  tmp << SpacegroupSymbolInfo(102, "", "P 42 n m", "", "P 4n -2n");

  tmp << SpacegroupSymbolInfo(103, "", "P 4 c c", "", "P 4 -2c");

  tmp << SpacegroupSymbolInfo(104, "", "P 4 n c", "", "P 4 -2n");

  tmp << SpacegroupSymbolInfo(105, "", "P 42 m c", "", "P 4c -2");

  tmp << SpacegroupSymbolInfo(106, "", "P 42 b c", "", "P 4c -2ab");

  tmp << SpacegroupSymbolInfo(107, "", "I 4 m m", "", "I 4 -2");

  tmp << SpacegroupSymbolInfo(108, "", "I 4 c m", "", "I 4 -2c");

  tmp << SpacegroupSymbolInfo(109, "", "I 41 m d", "", "I 4bw -2");

  tmp << SpacegroupSymbolInfo(110, "", "I 41 c d", "", "I 4bw -2c");

  tmp << SpacegroupSymbolInfo(111, "", "P -4 2 m", "", "P -4 2");

  tmp << SpacegroupSymbolInfo(112, "", "P -4 2 c", "", "P -4 2c");

  tmp << SpacegroupSymbolInfo(113, "", "P -4 21 m", "", "P -4 2ab");

  tmp << SpacegroupSymbolInfo(114, "", "P -4 21 c", "", "P -4 2n");

  tmp << SpacegroupSymbolInfo(115, "", "P -4 m 2", "", "P -4 -2");

  tmp << SpacegroupSymbolInfo(116, "", "P -4 c 2", "", "P -4 -2c");

  tmp << SpacegroupSymbolInfo(117, "", "P -4 b 2", "", "P -4 -2ab");

  tmp << SpacegroupSymbolInfo(118, "", "P -4 n 2", "", "P -4 -2n");

  tmp << SpacegroupSymbolInfo(119, "", "I -4 m 2", "", "I -4 -2");

  tmp << SpacegroupSymbolInfo(120, "", "I -4 c 2", "", "I -4 -2c");

  tmp << SpacegroupSymbolInfo(121, "", "I -4 2 m", "", "I -4 2");

  tmp << SpacegroupSymbolInfo(122, "", "I -4 2 d", "", "I -4 2bw");

  tmp << SpacegroupSymbolInfo(123, "", "P 4/m m m", "", "-P 4 2");

  tmp << SpacegroupSymbolInfo(124, "", "P 4/m c c", "", "-P 4 2c");

  tmp << SpacegroupSymbolInfo(125, "1", "P 4/n b m", "1", "P 4 2 -1ab");
  tmp << SpacegroupSymbolInfo(125, "2", "P 4/n b m", "2", "-P 4a 2b");

  tmp << SpacegroupSymbolInfo(126, "1", "P 4/n n c", "1", "P 4 2 -1n");
  tmp << SpacegroupSymbolInfo(126, "2", "P 4/n n c", "2", "-P 4a 2bc");

  tmp << SpacegroupSymbolInfo(127, "", "P 4/m b m", "", "-P 4 2ab");

  tmp << SpacegroupSymbolInfo(128, "", "P 4/m n c", "", "-P 4 2n");

  tmp << SpacegroupSymbolInfo(129, "1", "P 4/n m m", "1", "P 4ab 2ab -1ab");
  tmp << SpacegroupSymbolInfo(129, "2", "P 4/n m m", "2", "-P 4a 2a");

  tmp << SpacegroupSymbolInfo(130, "1", "P 4/n c c", "1", "P 4ab 2n -1ab");
  tmp << SpacegroupSymbolInfo(130, "2", "P 4/n c c", "2", "-P 4a 2ac");

  tmp << SpacegroupSymbolInfo(131, "", "P 42/m m c", "", "-P 4c 2");

  tmp << SpacegroupSymbolInfo(132, "", "P 42/m c m", "", "-P 4c 2c");

  tmp << SpacegroupSymbolInfo(133, "1", "P 42/n b c", "1", "P 4n 2c -1n");
  tmp << SpacegroupSymbolInfo(133, "2", "P 42/n b c", "2", "-P 4ac 2b");

  tmp << SpacegroupSymbolInfo(134, "1", "P 42/n n m", "1", "P 4n 2 -1n");
  tmp << SpacegroupSymbolInfo(134, "2", "P 42/n n m", "2", "-P 4ac 2bc");

  tmp << SpacegroupSymbolInfo(135, "", "P 42/m b c", "", "-P 4c 2ab");

  tmp << SpacegroupSymbolInfo(136, "", "P 42/m n m", "", "-P 4n 2n");

  tmp << SpacegroupSymbolInfo(137, "1", "P 42/n m c", "1", "P 4n 2n -1n");
  tmp << SpacegroupSymbolInfo(137, "2", "P 42/n m c", "2", "-P 4ac 2a");

  tmp << SpacegroupSymbolInfo(138, "1", "P 42/n c m", "1", "P 4n 2ab -1n");
  tmp << SpacegroupSymbolInfo(138, "2", "P 42/n c m", "2", "-P 4ac 2ac");

  tmp << SpacegroupSymbolInfo(139, "", "I 4/m m m", "", "-I 4 2");
  tmp << SpacegroupSymbolInfo(139, "", "F 4/m m m", "", "-F 4 2");

  tmp << SpacegroupSymbolInfo(140, "", "I 4/m c m", "", "-I 4 2c");

  tmp << SpacegroupSymbolInfo(141, "1", "I 41/a m d", "1", "I 4bw 2bw -1bw");
  tmp << SpacegroupSymbolInfo(141, "2", "I 41/a m d", "2", "-I 4bd 2");

  tmp << SpacegroupSymbolInfo(142, "1", "I 41/a c d", "1", "I 4bw 2aw -1bw");
  tmp << SpacegroupSymbolInfo(142, "2", "I 41/a c d", "2", "-I 4bd 2c");

  tmp << SpacegroupSymbolInfo(143, "", "P 3", "", "P 3");

  tmp << SpacegroupSymbolInfo(144, "", "P 31", "", "P 31");

  tmp << SpacegroupSymbolInfo(145, "", "P 32", "", "P 32");

  tmp << SpacegroupSymbolInfo(146, "H", "R 3", "H", "R 3");
  tmp << SpacegroupSymbolInfo(146, "R", "R 3", "R", "P 3*");

  tmp << SpacegroupSymbolInfo(147, "", "P -3", "", "-P 3");

  tmp << SpacegroupSymbolInfo(148, "H", "R -3", "H", "-R 3");
  tmp << SpacegroupSymbolInfo(148, "R", "R -3", "R", "-P 3*");

  tmp << SpacegroupSymbolInfo(149, "", "P 3 1 2", "", "P 3 2");

  tmp << SpacegroupSymbolInfo(150, "", "P 3 2 1", "", "P 3 2\"");

  tmp << SpacegroupSymbolInfo(151, "", "P 31 1 2", "", "P 31 2c (0 0 1)");

  tmp << SpacegroupSymbolInfo(152, "", "P 31 2 1", "", "P 31 2\"");

  tmp << SpacegroupSymbolInfo(153, "", "P 32 1 2", "", "P 32 2c (0 0 -1)");

  tmp << SpacegroupSymbolInfo(154, "", "P 32 2 1", "", "P 32 2\"");

  tmp << SpacegroupSymbolInfo(155, "H", "R 32", "H", "R 3 2\"");
  tmp << SpacegroupSymbolInfo(155, "R", "R 32", "R", "P 3* 2");

  tmp << SpacegroupSymbolInfo(156, "", "P 3 m 1", "", "P 3 -2\"");

  tmp << SpacegroupSymbolInfo(157, "", "P 3 1 m", "", "P 3 -2");

  tmp << SpacegroupSymbolInfo(158, "", "P 3 c 1", "", "P 3 -2\"c");

  tmp << SpacegroupSymbolInfo(159, "", "P 3 1 c", "", "P 3 -2c");

  tmp << SpacegroupSymbolInfo(160, "H", "R 3 m", "H", "R 3 -2\"");
  tmp << SpacegroupSymbolInfo(160, "R", "R 3 m", "R", "P 3* -2");

  tmp << SpacegroupSymbolInfo(161, "H", "R 3 c", "H", "R 3 -2\"c");
  tmp << SpacegroupSymbolInfo(161, "R", "R 3 c", "R", "P 3* -2n");

  tmp << SpacegroupSymbolInfo(162, "", "P -3 1 m", "", "-P 3 2");

  tmp << SpacegroupSymbolInfo(163, "", "P -3 1 c", "", "-P 3 2c");

  tmp << SpacegroupSymbolInfo(164, "", "P -3 m 1", "", "-P 3 2\"");

  tmp << SpacegroupSymbolInfo(165, "", "P -3 c 1", "", "-P 3 2\"c");

  tmp << SpacegroupSymbolInfo(166, "H", "R -3 m", "H", "-R 3 2\"");
  tmp << SpacegroupSymbolInfo(166, "R", "R -3 m", "R", "-P 3* 2");

  tmp << SpacegroupSymbolInfo(167, "H", "R -3 c", "H", "-R 3 2\"c");
  tmp << SpacegroupSymbolInfo(167, "R", "R -3 c", "R", "-P 3* 2n");

  tmp << SpacegroupSymbolInfo(168, "", "P 6", "", "P 6");

  tmp << SpacegroupSymbolInfo(169, "", "P 61", "", "P 61");

  tmp << SpacegroupSymbolInfo(170, "", "P 65", "", "P 65");

  tmp << SpacegroupSymbolInfo(171, "", "P 62", "", "P 62");

  tmp << SpacegroupSymbolInfo(172, "", "P 64", "", "P 64");

  tmp << SpacegroupSymbolInfo(173, "", "P 63", "", "P 6c");

  tmp << SpacegroupSymbolInfo(174, "", "P -6", "", "P -6");

  tmp << SpacegroupSymbolInfo(175, "", "P 6/m", "", "-P 6");

  tmp << SpacegroupSymbolInfo(176, "", "P 63/m", "", "-P 6c");

  tmp << SpacegroupSymbolInfo(177, "", "P 6 2 2", "", "P 6 2");

  tmp << SpacegroupSymbolInfo(178, "", "P 61 2 2", "", "P 61 2 (0 0 -1)");

  tmp << SpacegroupSymbolInfo(179, "", "P 65 2 2", "", "P 65 2 (0 0 1)");

  tmp << SpacegroupSymbolInfo(180, "", "P 62 2 2", "", "P 62 2c (0 0 1)");

  tmp << SpacegroupSymbolInfo(181, "", "P 64 2 2", "", "P 64 2c (0 0 -1)");

  tmp << SpacegroupSymbolInfo(182, "", "P 63 2 2", "", "P 6c 2c");

  tmp << SpacegroupSymbolInfo(183, "", "P 6 m m", "", "P 6 -2");

  tmp << SpacegroupSymbolInfo(184, "", "P 6 c c", "", "P 6 -2c");

  tmp << SpacegroupSymbolInfo(185, "", "P 63 c m", "", "P 6c -2");

  tmp << SpacegroupSymbolInfo(186, "", "P 63 m c", "", "P 6c -2c");

  tmp << SpacegroupSymbolInfo(187, "", "P -6 m 2", "", "P -6 2");

  tmp << SpacegroupSymbolInfo(188, "", "P -6 c 2", "", "P -6c 2");

  tmp << SpacegroupSymbolInfo(189, "", "P -6 2 m", "", "P -6 -2");

  tmp << SpacegroupSymbolInfo(190, "", "P -6 2 c", "", "P -6c -2c");

  tmp << SpacegroupSymbolInfo(191, "", "P 6/m m m", "", "-P 6 2");

  tmp << SpacegroupSymbolInfo(192, "", "P 6/m c c", "", "-P 6 2c");

  tmp << SpacegroupSymbolInfo(193, "", "P 63/m c m", "", "-P 6c 2");

  tmp << SpacegroupSymbolInfo(194, "", "P 63/m m c", "", "-P 6c 2c");

  tmp << SpacegroupSymbolInfo(195, "", "P 2 3", "", "P 2 2 3");

  tmp << SpacegroupSymbolInfo(196, "", "F 2 3", "", "F 2 2 3");

  tmp << SpacegroupSymbolInfo(197, "", "I 2 3", "", "I 2 2 3");

  tmp << SpacegroupSymbolInfo(198, "", "P 21 3", "", "P 2ac 2ab 3");

  tmp << SpacegroupSymbolInfo(199, "", "I 21 3", "", "I 2b 2c 3");

  tmp << SpacegroupSymbolInfo(200, "", "P m -3", "", "-P 2 2 3");
  tmp << SpacegroupSymbolInfo(200, "", "P m 3", "", "-P 2 2 3");

  tmp << SpacegroupSymbolInfo(201, "1", "P n -3", "1", "P 2 2 3 -1n");
  tmp << SpacegroupSymbolInfo(201, "2", "P n -3", "2", "-P 2ab 2bc 3");
  tmp << SpacegroupSymbolInfo(201, "1", "P n 3", "1", "P 2 2 3 -1n");

  tmp << SpacegroupSymbolInfo(202, "", "F m -3", "", "-F 2 2 3");
  tmp << SpacegroupSymbolInfo(202, "", "F m 3", "", "-F 2 2 3");

  tmp << SpacegroupSymbolInfo(203, "1", "F d -3", "1", "F 2 2 3 -1d");
  tmp << SpacegroupSymbolInfo(203, "2", "F d -3", "2", "-F 2uv 2vw 3");
  tmp << SpacegroupSymbolInfo(203, "1", "F d 3", "1", "F 2 2 3 -1d");

  tmp << SpacegroupSymbolInfo(204, "", "I m -3", "", "-I 2 2 3");
  tmp << SpacegroupSymbolInfo(204, "", "I m 3", "", "-I 2 2 3");

  tmp << SpacegroupSymbolInfo(205, "", "P a -3", "", "-P 2ac 2ab 3");
  tmp << SpacegroupSymbolInfo(205, "", "P a 3", "", "-P 2ac 2ab 3");

  tmp << SpacegroupSymbolInfo(206, "", "I a -3", "", "-I 2b 2c 3");
  tmp << SpacegroupSymbolInfo(206, "", "I a 3", "", "-I 2b 2c 3");

  tmp << SpacegroupSymbolInfo(207, "", "P 4 3 2", "", "P 4 2 3");

  tmp << SpacegroupSymbolInfo(208, "", "P 42 3 2", "", "P 4n 2 3");

  tmp << SpacegroupSymbolInfo(209, "", "F 4 3 2", "", "F 4 2 3");

  tmp << SpacegroupSymbolInfo(210, "", "F 41 3 2", "", "F 4d 2 3");

  tmp << SpacegroupSymbolInfo(211, "", "I 4 3 2", "", "I 4 2 3");

  tmp << SpacegroupSymbolInfo(212, "", "P 43 3 2", "", "P 4acd 2ab 3");

  tmp << SpacegroupSymbolInfo(213, "", "P 41 3 2", "", "P 4bd 2ab 3");

  tmp << SpacegroupSymbolInfo(214, "", "I 41 3 2", "", "I 4bd 2c 3");

  tmp << SpacegroupSymbolInfo(215, "", "P -4 3 m", "", "P -4 2 3");

  tmp << SpacegroupSymbolInfo(216, "", "F -4 3 m", "", "F -4 2 3");

  tmp << SpacegroupSymbolInfo(217, "", "I -4 3 m", "", "I -4 2 3");

  tmp << SpacegroupSymbolInfo(218, "", "P -4 3 n", "", "P -4n 2 3");

  tmp << SpacegroupSymbolInfo(219, "", "F -4 3 c", "", "F -4c 2 3");

  tmp << SpacegroupSymbolInfo(220, "", "I -4 3 d", "", "I -4bd 2c 3");

  tmp << SpacegroupSymbolInfo(221, "", "P m -3 m", "", "-P 4 2 3");
  tmp << SpacegroupSymbolInfo(221, "", "P m 3 m", "", "-P 4 2 3");

  tmp << SpacegroupSymbolInfo(222, "1", "P n -3 n", "1", "P 4 2 3 -1n");
  tmp << SpacegroupSymbolInfo(222, "2", "P n -3 n", "2", "-P 4a 2bc 3");
  tmp << SpacegroupSymbolInfo(222, "1", "P n 3 n", "1", "P 4 2 3 -1n");

  tmp << SpacegroupSymbolInfo(223, "", "P m -3 n", "", "-P 4n 2 3");
  tmp << SpacegroupSymbolInfo(223, "", "P m 3 n", "", "-P 4n 2 3");

  tmp << SpacegroupSymbolInfo(224, "1", "P n -3 m", "1", "P 4n 2 3 -1n");
  tmp << SpacegroupSymbolInfo(224, "2", "P n -3 m", "2", "-P 4bc 2bc 3");
  tmp << SpacegroupSymbolInfo(224, "1", "P n 3 m", "1", "P 4n 2 3 -1n");

  tmp << SpacegroupSymbolInfo(225, "", "F m -3 m", "", "-F 4 2 3");
  tmp << SpacegroupSymbolInfo(225, "", "F m 3 m", "", "-F 4 2 3");

  tmp << SpacegroupSymbolInfo(226, "", "F m -3 c", "", "-F 4c 2 3");
  tmp << SpacegroupSymbolInfo(226, "", "F m 3 c", "", "-F 4c 2 3");

  tmp << SpacegroupSymbolInfo(227, "1", "F d -3 m", "1", "F 4d 2 3 -1d");
  tmp << SpacegroupSymbolInfo(227, "2", "F d -3 m", "2", "-F 4vw 2vw 3");
  tmp << SpacegroupSymbolInfo(227, "1", "F d 3 m", "1", "F 4d 2 3 -1d");

  tmp << SpacegroupSymbolInfo(228, "1", "F d -3 c", "1", "F 4d 2 3 -1cd");
  tmp << SpacegroupSymbolInfo(228, "2", "F d -3 c", "2", "-F 4cvw 2vw 3");
  tmp << SpacegroupSymbolInfo(228, "1", "F d 3 c", "1", "F 4d 2 3 -1cd");

  tmp << SpacegroupSymbolInfo(229, "", "I m -3 m", "", "-I 4 2 3");
  tmp << SpacegroupSymbolInfo(229, "", "I m 3 m", "", "-I 4 2 3");

  tmp << SpacegroupSymbolInfo(230, "", "I a -3 d", "", "-I 4bd 2c 3");
  tmp << SpacegroupSymbolInfo(230, "", "I a 3 d", "", "-I 4bd 2c 3");

  return tmp;
}