// File Automatically generated by eLiSe

#include "general/all.h"
#include "private/all.h"


class cCodeGenEqPlanInconnuFormel: public cElCompiledFonc
{
   public :

      cCodeGenEqPlanInconnuFormel();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetCoefBar_0_0(double);
      void SetCoefBar_0_1(double);
      void SetCoefBar_0_2(double);
      void SetCoefBar_1_0(double);
      void SetCoefBar_1_1(double);
      void SetCoefBar_1_2(double);
      void SetCoefBar_2_0(double);
      void SetCoefBar_2_1(double);
      void SetCoefBar_2_2(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocCoefBar_0_0;
      double mLocCoefBar_0_1;
      double mLocCoefBar_0_2;
      double mLocCoefBar_1_0;
      double mLocCoefBar_1_1;
      double mLocCoefBar_1_2;
      double mLocCoefBar_2_0;
      double mLocCoefBar_2_1;
      double mLocCoefBar_2_2;
};
