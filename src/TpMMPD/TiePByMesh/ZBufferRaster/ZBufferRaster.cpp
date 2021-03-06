#include "ZBufferRaster.h"

string aPatFIm, aMesh, aOri;
int nInt = 0;
Pt2di aSzW;
int rech=1;
double distMax = DBL_MAX;
bool withLbl = false;


int ZBufferRaster_main(int argc,char ** argv)
{
    ElInitArgMain
            (
                argc,argv,
                //mandatory arguments
                LArgMain()
                << EAMC(aMesh, "Mesh",     eSAM_IsExistFile)
                << EAMC(aPatFIm, "Image",  eSAM_IsPatFile)
                << EAMC(aOri, "Ori",       eSAM_IsExistDirOri),
                //optional arguments
                LArgMain()
                << EAM(nInt, "nInt", true, "niveau Interaction")
                << EAM(aSzW,  "aSzw",true,"if visu [x,y]")
                << EAM(rech,  "rech",true,"cal ZBuff in img Resample - default =1.0 - 2 => 2 times <")
                << EAM(distMax,  "distMax",true,"limit distant cover Maximum from camera - default = NO LIMIT")
                << EAM(withLbl,  "withLbl",true,"Do image label (image label of triangle in surface)")
                );

    if (MMVisualMode) return EXIT_SUCCESS;

    string aDir, aPatIm;
    SplitDirAndFile(aDir, aPatIm, aPatFIm);
    cInterfChantierNameManipulateur * aICNM = cInterfChantierNameManipulateur::BasicAlloc(aDir);
    vector<string>  vImg = *(aICNM->Get(aPatIm));

    StdCorrecNameOrient(aOri,aDir,true);

    InitOutil * aInitMesh = new InitOutil(aMesh);

    vector<triangle*> aVTriMesh = aInitMesh->getmPtrListTri();

    vector<cTri3D> aVTri;

    for (int aKTri=0; aKTri<int(aVTriMesh.size()); aKTri++)
    {
        triangle * aTriMesh = aVTriMesh[aKTri];
        cTri3D aTri (   aTriMesh->getSommet(0),
                        aTriMesh->getSommet(1),
                        aTriMesh->getSommet(2),
                        aKTri
                    );
        aVTri.push_back(aTri);
    }


    delete(aInitMesh);



    cAppliZBufferRaster * aAppli = new cAppliZBufferRaster(aICNM, aDir, aOri, aVTri, vImg);

    aAppli->NInt() = nInt;
    if (EAMIsInit(&aSzW))
    {
        aAppli->SzW() = aSzW;
    }
    if (EAMIsInit(&distMax))
    {
        aAppli->DistMax() = distMax;
    }
    aAppli->WithImgLabel() = withLbl;
    aAppli->Reech() = 1.0/double(rech);
    aAppli->SetNameMesh(aMesh);
    aAppli->DoAllIm();


    return EXIT_SUCCESS;
}
