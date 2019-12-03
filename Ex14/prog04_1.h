//----三角形一つに関るデータ群----//
typedef struct{
  double ax, ay; //点Aの座標
  double bx, by; //点Bの座標
  double cx, cy; //点Cの座標
  double x;      //重心X
  double y;      //重心Y
  double s;      //面積
}Point;

Point abc[2];//三角形ごとの変数//

//----プロトタイプ宣言----//
//３点の平面座標をキーボードから入力して構造体に格納する関数//
void InputTriangle (Point *);
//三角形の重心を求める関数//
void CalcTriangleCentroid (Point *);
//３点が三角形を成すかどうかを判定する関数//
int IsTriangle (Point *);//戻値(0:三角形、-1:三角形ではない)
//三角形の面積を求める関数//
void GetTriangleArea (Point *);
