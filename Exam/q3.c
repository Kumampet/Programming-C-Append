#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct typedef { /* 3次元空間の点を表す座標の構造体 */
  double x;
  double y;
  double z;
} Point;

struct typedef { /* 二つの点の情報とその間の距離を格納する構造体 */
  double dst; /* 二点間の距離 */
  Point *p1; /* 一つの点へのポインタ */
  Point *p2; /* 一つの点へのポインタ */
} Dinfo;

void dcalc(Point *, Dinfo *, int);
double distance(Point, Point);


int main()
{
  Point p[10]; /* 点の数は最大 10 個を仮定 */
  Dinfo di[45]; /* 10C2=45 なので二点の組合せは最大 45 組 */
  Dinfo dimax; /* 距離最大となる二点の情報を入れる構造体 */
  int i, n;

  printf("Input coordinates:\n");
  for ( i=0; i<10; i++ ){
    if ( scanf( "%lf%lf%lf", p[i].x, p[i].y, p[i].z ) != 3 ) break;
  }
  n = i;
  /* 距離計算等を行う関数を呼ぶ */
  dcalc(p);
  /* 距離の最大値を探す。探した結果は dimax 構造体に記録 */
  dimax.dst = 0.0;
  for ( i=0; i<n*(n-1)/2; i++ ){
    if (_____(6)_____ > dimax.dst) {
      _____(7)_____;
    }
  }
  /* 結果表示:距離の最大値と二点の座標を表示 */
  printf("Maximum distance: %f\n", dimax.dst);
  printf("between (%.3f %.3f %.3f) and (%.3f %.3f %.3f)\n", ____(8)____x,
	 ____(8)____y, ____(8)____z, ____(9)____x, ____(9)____y, ____(9)____z);
  return 0;
}

/* Point 型の配列データから、二つの点の組み合わせ全てについて二点間の
距離を計算し、Dinfo 型の配列に距離と二つの点の情報を格納する。
なお個々の距離の計算は別の関数を呼んで行う。第 3 引数は点の数。 */

void dcalc(Point *p, Dinfo *d, int n)
{
  int i, j, k=0;
  for ( i=0; i<n-1; i++ ){ /* 片方の点の添え字 */
    for ( ___(10)___; j<n; j++ ){ /* もう一方の点の添え字 */
      d[k].dst = distance( _____(11)_____ ); /* 距離計算関数を呼ぶ */
      d[k].p1 = ____(12)____; /* 計算に使われた点へのポインタを格納 */
      d[k].p2 = ____(13)____;
      k++;
    }
  }
}


/* 二つの点を引数にとり、その間の距離を計算して返す関数 */
double distance(Point p1, Point p2)
{
  Point v;
  v.x = p2.x-p1.x; /* いったん座標値の差を新しい変数に格納 */
  v.y = p2.y-p1.y;
  v.z = p2.z-p1.z;
  return sqrt( ______________(14)_______________ );
}

//[プログラム2]
void dcalc(Point *p, Dinfo *d, int n)
{
  Point *q, *r;
  for ( q=p; q<p+n-1; q++ ){ /* q が&p[0]から&p[n-2]まで変化 */
    for ( ___(15)___; ___(16)___; r++ ){ /* r が&p[n-1]まで変化 */
      d->dst = distance( _____(17)_____ ); /* 距離計算関数を呼ぶ */
      ___(18)___ = q; /* 計算に使われた点へのポインタを格納 */
      ___(19)___ = r;
      ___(20)___; /* 配列の要素を一つ先に */
    }
  }
}
