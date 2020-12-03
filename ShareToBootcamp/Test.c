// This is test file

/* 

Creat to check the value is valid or not
void getValidvalue(const char* cateErrMsg, const char* byWeightErrMsg, const struct StockRecord stockRecord[], int num);

void getValidvalue(const char *cateErrMsg, const char *byWeightErrMsg, const struct StockRecord stockRecord[], int num)
{
  int valid = 1;

  while (valid == 1)
  {
    if (stockRecord[num].salesRecord.category < MIN_CATEGORY || stockRecord[num].salesRecord.category > MAX_CATEGORY)
    {
      printf(cateErrMsg, MAX_CATEGORY, MIN_CATEGORY);
      scanf("%d,%lf,%d,%30[^\n]", &stockRecord[num].salesRecord.category,
            &stockRecord[num].salesRecord.price,
            &stockRecord[num].salesRecord.byWeight,
            stockRecord[num].product);
      clearKeyboard();
    }
    else
    {
      valid = 0;
    }
  }

  while (valid == 1)
  {
    if (stockRecord[num].salesRecord.byWeight < 0 || stockRecord[num].salesRecord.byWeight > 1)
    {
      printf(byWeightErrMsg);
      scanf("%d,%30[^\n]", &stockRecord[num].salesRecord.byWeight, stockRecord[num].product);
      clearKeyboard();
    }
    else
    {
      valid = 0;
    }
  }
}

if I use this fuction:
getValidvalue("Invalid Category - Enter a number between %d and %d: ",
              "Invalid soldByWeight - Enter a number between 0 and 1: ",
              &stockRecord[i].salesRecord.category, i);

*/