typedef struct {      /* 個人レコード                          */
  char name[20];     /* 名前（簡単のため、姓だけ）            */
  int  birthday[3];  /* 誕生日（要素0:西暦 要素1:月 要素2:日）*/
  int  gender;       /* 性別 (0:男性, 1:女性)                 */
}Record;
