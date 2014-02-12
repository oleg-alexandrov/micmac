// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"


class cEqAppui_PTInc_M2CPolyn6: public cElCompiledFonc
{
   public :

      cEqAppui_PTInc_M2CPolyn6();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetPolyn6_State_0_0(double);
      void SetPolyn6_State_1_0(double);
      void SetPolyn6_State_2_0(double);
      void SetScNorm(double);
      void SetXIm(double);
      void SetYIm(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocPolyn6_State_0_0;
      double mLocPolyn6_State_1_0;
      double mLocPolyn6_State_2_0;
      double mLocScNorm;
      double mLocXIm;
      double mLocYIm;
};
