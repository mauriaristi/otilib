
// ****************************************************************************************************
void der_r_sin(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=sin(x0)
            case 1:
                derivs[1]=cos(x0)
            case 2:
                derivs[2]=-sin(x0)
            case 3:
                derivs[3]=-cos(x0)
            case 4:
                derivs[4]=sin(x0)
            case 5:
                derivs[5]=cos(x0)
            case 6:
                derivs[6]=-sin(x0)
            case 7:
                derivs[7]=-cos(x0)
            case 8:
                derivs[8]=sin(x0)
            case 9:
                derivs[9]=cos(x0)
            case 10:
                derivs[10]=-sin(x0)
            case 11:
                derivs[11]=-cos(x0)
            case 12:
                derivs[12]=sin(x0)
            case 13:
                derivs[13]=cos(x0)
            case 14:
                derivs[14]=-sin(x0)
            case 15:
                derivs[15]=-cos(x0)
            case 16:
                derivs[16]=sin(x0)
            case 17:
                derivs[17]=cos(x0)
            case 18:
                derivs[18]=-sin(x0)
            case 19:
                derivs[19]=-cos(x0)
            case 20:
                derivs[20]=sin(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_cos(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=cos(x0)
            case 1:
                derivs[1]=-sin(x0)
            case 2:
                derivs[2]=-cos(x0)
            case 3:
                derivs[3]=sin(x0)
            case 4:
                derivs[4]=cos(x0)
            case 5:
                derivs[5]=-sin(x0)
            case 6:
                derivs[6]=-cos(x0)
            case 7:
                derivs[7]=sin(x0)
            case 8:
                derivs[8]=cos(x0)
            case 9:
                derivs[9]=-sin(x0)
            case 10:
                derivs[10]=-cos(x0)
            case 11:
                derivs[11]=sin(x0)
            case 12:
                derivs[12]=cos(x0)
            case 13:
                derivs[13]=-sin(x0)
            case 14:
                derivs[14]=-cos(x0)
            case 15:
                derivs[15]=sin(x0)
            case 16:
                derivs[16]=cos(x0)
            case 17:
                derivs[17]=-sin(x0)
            case 18:
                derivs[18]=-cos(x0)
            case 19:
                derivs[19]=sin(x0)
            case 20:
                derivs[20]=cos(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_tan(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=tan(x0)
            case 1:
                derivs[1]=pow(tan(x0),2)+1
            case 2:
                derivs[2]=2*(pow(tan(x0),2)+1)*tan(x0)
            case 3:
                derivs[3]=2*(pow(tan(x0),2)+1)*(3*pow(tan(x0),2)+1)
            case 4:
                derivs[4]=8*(pow(tan(x0),2)+1)*(3*pow(tan(x0),2)+2)*tan(x0)
            case 5:
                derivs[5]=8*(pow(tan(x0),2)+1)*(2*pow(pow(tan(x0),2)+1,2)+11*(pow(tan(x0),2)+1)*pow(tan(x0),2)+2*pow(tan(x0),4))
            case 6:
                derivs[6]=16*(pow(tan(x0),2)+1)*(17*pow(pow(tan(x0),2)+1,2)+26*(pow(tan(x0),2)+1)*pow(tan(x0),2)+2*pow(tan(x0),4))*tan(x0)
            case 7:
                derivs[7]=16*(pow(tan(x0),2)+1)*(17*pow(pow(tan(x0),2)+1,3)+180*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),2)+114*(pow(tan(x0),2)+1)*pow(tan(x0),4)+4*pow(tan(x0),6))
            case 8:
                derivs[8]=128*(pow(tan(x0),2)+1)*(62*pow(pow(tan(x0),2)+1,3)+192*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),2)+60*(pow(tan(x0),2)+1)*pow(tan(x0),4)+pow(tan(x0),6))*tan(x0)
            case 9:
                derivs[9]=128*(pow(tan(x0),2)+1)*(62*pow(pow(tan(x0),2)+1,4)+1072*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),2)+1452*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),4)+247*(pow(tan(x0),2)+1)*pow(tan(x0),6)+2*pow(tan(x0),8))
            case 10:
                derivs[10]=256*(pow(tan(x0),2)+1)*(1382*pow(pow(tan(x0),2)+1,4)+7192*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),2)+5097*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),4)+502*(pow(tan(x0),2)+1)*pow(tan(x0),6)+2*pow(tan(x0),8))*tan(x0)
            case 11:
                derivs[11]=256*(pow(tan(x0),2)+1)*(1382*pow(pow(tan(x0),2)+1,5)+35396*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),2)+83021*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),4)+34096*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),6)+2026*(pow(tan(x0),2)+1)*pow(tan(x0),8)+4*pow(tan(x0),10))
            case 12:
                derivs[12]=1024*(pow(tan(x0),2)+1)*(21844*pow(pow(tan(x0),2)+1,5)+171511*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),2)+217186*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),4)+55196*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),6)+2036*(pow(tan(x0),2)+1)*pow(tan(x0),8)+2*pow(tan(x0),10))*tan(x0)
            case 13:
                derivs[13]=1024*(pow(tan(x0),2)+1)*(21844*pow(pow(tan(x0),2)+1,6)+776661*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),2)+2801040*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),4)+2123860*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),6)+349500*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),8)+8166*(pow(tan(x0),2)+1)*pow(tan(x0),10)+4*pow(tan(x0),12))
            case 14:
                derivs[14]=2048*(pow(tan(x0),2)+1)*(929569*pow(pow(tan(x0),2)+1,6)+10262046*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),2)+20376780*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),4)+9893440*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),6)+1089330*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),8)+16356*(pow(tan(x0),2)+1)*pow(tan(x0),10)+4*pow(tan(x0),12))*tan(x0)
            case 15:
                derivs[15]=2048*(pow(tan(x0),2)+1)*(929569*pow(pow(tan(x0),2)+1,7)+43800104*pow(pow(tan(x0),2)+1,6)*pow(tan(x0),2)+225028452*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),4)+273021880*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),6)+88951490*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),8)+6715896*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),10)+65476*(pow(tan(x0),2)+1)*pow(tan(x0),12)+8*pow(tan(x0),14))
            case 16:
                derivs[16]=32768*(pow(tan(x0),2)+1)*(6404582*pow(pow(tan(x0),2)+1,7)+94582204*pow(pow(tan(x0),2)+1,6)*pow(tan(x0),2)+271154544*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),4)+215114420*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),6)+48673180*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),8)+2567568*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),10)+16376*(pow(tan(x0),2)+1)*pow(tan(x0),12)+pow(tan(x0),14))*tan(x0)
            case 17:
                derivs[17]=32768*(pow(tan(x0),2)+1)*(6404582*pow(pow(tan(x0),2)+1,8)+386219924*pow(pow(tan(x0),2)+1,7)*pow(tan(x0),2)+2679923576*pow(pow(tan(x0),2)+1,6)*pow(tan(x0),4)+4759655468*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),6)+2589202820*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),8)+417628688*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),10)+15618296*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),12)+65519*(pow(tan(x0),2)+1)*pow(tan(x0),14)+2*pow(tan(x0),16))
            case 18:
                derivs[18]=65536*(pow(tan(x0),2)+1)*(443861162*pow(pow(tan(x0),2)+1,8)+8449606544*pow(pow(tan(x0),2)+1,7)*pow(tan(x0),2)+33038431436*pow(pow(tan(x0),2)+1,6)*pow(tan(x0),4)+38914744088*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),6)+15034157540*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),8)+1764224528*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),10)+47313521*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),12)+131054*(pow(tan(x0),2)+1)*pow(tan(x0),14)+2*pow(tan(x0),16))*tan(x0)
            case 19:
                derivs[19]=65536*(pow(tan(x0),2)+1)*(443861162*pow(pow(tan(x0),2)+1,9)+33338320548*pow(pow(tan(x0),2)+1,8)*pow(tan(x0),2)+300385861884*pow(pow(tan(x0),2)+1,7)*pow(tan(x0),4)+734941248720*pow(pow(tan(x0),2)+1,6)*pow(tan(x0),6)+602284346916*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),8)+169748045208*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),10)+14728871997*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),12)+285846936*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),14)+524250*(pow(tan(x0),2)+1)*pow(tan(x0),16)+4*pow(tan(x0),18))
            case 20:
                derivs[20]=262144*(pow(tan(x0),2)+1)*(18888466084*pow(pow(tan(x0),2)+1,9)+450408304350*pow(pow(tan(x0),2)+1,8)*pow(tan(x0),2)+2303955320616*pow(pow(tan(x0),2)+1,7)*pow(tan(x0),4)+3776863064352*pow(pow(tan(x0),2)+1,6)*pow(tan(x0),6)+2231223153768*pow(pow(tan(x0),2)+1,5)*pow(tan(x0),8)+468556729011*pow(pow(tan(x0),2)+1,4)*pow(tan(x0),10)+30458208270*pow(pow(tan(x0),2)+1,3)*pow(tan(x0),12)+430867404*pow(pow(tan(x0),2)+1,2)*pow(tan(x0),14)+524268*(pow(tan(x0),2)+1)*pow(tan(x0),16)+2*pow(tan(x0),18))*tan(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_asin(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=asin(x0)
            case 1:
                derivs[1]=pow(1-pow(x0,2),-1.0/2.0)
            case 2:
                derivs[2]=x0/pow(1-pow(x0,2),3.0/2.0)
            case 3:
                derivs[3]=(3*pow(x0,2)/(1-pow(x0,2))+1)/pow(1-pow(x0,2),3.0/2.0)
            case 4:
                derivs[4]=3*x0*(5*pow(x0,2)/(1-pow(x0,2))+3)/pow(1-pow(x0,2),5.0/2.0)
            case 5:
                derivs[5]=3*(35*pow(x0,4)/pow(1-pow(x0,2),2)+30*pow(x0,2)/(1-pow(x0,2))+3)/pow(1-pow(x0,2),5.0/2.0)
            case 6:
                derivs[6]=15*x0*(63*pow(x0,4)/pow(1-pow(x0,2),2)+70*pow(x0,2)/(1-pow(x0,2))+15)/pow(1-pow(x0,2),7.0/2.0)
            case 7:
                derivs[7]=45*(231*pow(x0,6)/pow(1-pow(x0,2),3)+315*pow(x0,4)/pow(1-pow(x0,2),2)+105*pow(x0,2)/(1-pow(x0,2))+5)/pow(1-pow(x0,2),7.0/2.0)
            case 8:
                derivs[8]=315*x0*(429*pow(x0,6)/pow(1-pow(x0,2),3)+693*pow(x0,4)/pow(1-pow(x0,2),2)+315*pow(x0,2)/(1-pow(x0,2))+35)/pow(1-pow(x0,2),9.0/2.0)
            case 9:
                derivs[9]=315*(6435*pow(x0,8)/pow(1-pow(x0,2),4)+12012*pow(x0,6)/pow(1-pow(x0,2),3)+6930*pow(x0,4)/pow(1-pow(x0,2),2)+1260*pow(x0,2)/(1-pow(x0,2))+35)/pow(1-pow(x0,2),9.0/2.0)
            case 10:
                derivs[10]=2835*x0*(12155*pow(x0,8)/pow(1-pow(x0,2),4)+25740*pow(x0,6)/pow(1-pow(x0,2),3)+18018*pow(x0,4)/pow(1-pow(x0,2),2)+4620*pow(x0,2)/(1-pow(x0,2))+315)/pow(1-pow(x0,2),11.0/2.0)
            case 11:
                derivs[11]=14175*(46189*pow(x0,10)/pow(1-pow(x0,2),5)+109395*pow(x0,8)/pow(1-pow(x0,2),4)+90090*pow(x0,6)/pow(1-pow(x0,2),3)+30030*pow(x0,4)/pow(1-pow(x0,2),2)+3465*pow(x0,2)/(1-pow(x0,2))+63)/pow(1-pow(x0,2),11.0/2.0)
            case 12:
                derivs[12]=155925*x0*(88179*pow(x0,10)/pow(1-pow(x0,2),5)+230945*pow(x0,8)/pow(1-pow(x0,2),4)+218790*pow(x0,6)/pow(1-pow(x0,2),3)+90090*pow(x0,4)/pow(1-pow(x0,2),2)+15015*pow(x0,2)/(1-pow(x0,2))+693)/pow(1-pow(x0,2),13.0/2.0)
            case 13:
                derivs[13]=467775*(676039*pow(x0,12)/pow(1-pow(x0,2),6)+1939938*pow(x0,10)/pow(1-pow(x0,2),5)+2078505*pow(x0,8)/pow(1-pow(x0,2),4)+1021020*pow(x0,6)/pow(1-pow(x0,2),3)+225225*pow(x0,4)/pow(1-pow(x0,2),2)+18018*pow(x0,2)/(1-pow(x0,2))+231)/pow(1-pow(x0,2),13.0/2.0)
            case 14:
                derivs[14]=6081075*x0*(1300075*pow(x0,12)/pow(1-pow(x0,2),6)+4056234*pow(x0,10)/pow(1-pow(x0,2),5)+4849845*pow(x0,8)/pow(1-pow(x0,2),4)+2771340*pow(x0,6)/pow(1-pow(x0,2),3)+765765*pow(x0,4)/pow(1-pow(x0,2),2)+90090*pow(x0,2)/(1-pow(x0,2))+3003)/pow(1-pow(x0,2),15.0/2.0)
            case 15:
                derivs[15]=42567525*(5014575*pow(x0,14)/pow(1-pow(x0,2),7)+16900975*pow(x0,12)/pow(1-pow(x0,2),6)+22309287*pow(x0,10)/pow(1-pow(x0,2),5)+14549535*pow(x0,8)/pow(1-pow(x0,2),4)+4849845*pow(x0,6)/pow(1-pow(x0,2),3)+765765*pow(x0,4)/pow(1-pow(x0,2),2)+45045*pow(x0,2)/(1-pow(x0,2))+429)/pow(1-pow(x0,2),15.0/2.0)
            case 16:
                derivs[16]=638512875*x0*(9694845*pow(x0,14)/pow(1-pow(x0,2),7)+35102025*pow(x0,12)/pow(1-pow(x0,2),6)+50702925*pow(x0,10)/pow(1-pow(x0,2),5)+37182145*pow(x0,8)/pow(1-pow(x0,2),4)+14549535*pow(x0,6)/pow(1-pow(x0,2),3)+2909907*pow(x0,4)/pow(1-pow(x0,2),2)+255255*pow(x0,2)/(1-pow(x0,2))+6435)/pow(1-pow(x0,2),17.0/2.0)
            case 17:
                derivs[17]=638512875*(300540195*pow(x0,16)/pow(1-pow(x0,2),8)+1163381400*pow(x0,14)/pow(1-pow(x0,2),7)+1825305300*pow(x0,12)/pow(1-pow(x0,2),6)+1487285800*pow(x0,10)/pow(1-pow(x0,2),5)+669278610*pow(x0,8)/pow(1-pow(x0,2),4)+162954792*pow(x0,6)/pow(1-pow(x0,2),3)+19399380*pow(x0,4)/pow(1-pow(x0,2),2)+875160*pow(x0,2)/(1-pow(x0,2))+6435)/pow(1-pow(x0,2),17.0/2.0)
            case 18:
                derivs[18]=10854718875*x0*(583401555*pow(x0,16)/pow(1-pow(x0,2),8)+2404321560*pow(x0,14)/pow(1-pow(x0,2),7)+4071834900*pow(x0,12)/pow(1-pow(x0,2),6)+3650610600*pow(x0,10)/pow(1-pow(x0,2),5)+1859107250*pow(x0,8)/pow(1-pow(x0,2),4)+535422888*pow(x0,6)/pow(1-pow(x0,2),3)+81477396*pow(x0,4)/pow(1-pow(x0,2),2)+5542680*pow(x0,2)/(1-pow(x0,2))+109395)/pow(1-pow(x0,2),19.0/2.0)
            case 19:
                derivs[19]=97692469875*(2268783825*pow(x0,18)/pow(1-pow(x0,2),9)+9917826435*pow(x0,16)/pow(1-pow(x0,2),8)+18032411700*pow(x0,14)/pow(1-pow(x0,2),7)+17644617900*pow(x0,12)/pow(1-pow(x0,2),6)+10039179150*pow(x0,10)/pow(1-pow(x0,2),5)+3346393050*pow(x0,8)/pow(1-pow(x0,2),4)+624660036*pow(x0,6)/pow(1-pow(x0,2),3)+58198140*pow(x0,4)/pow(1-pow(x0,2),2)+2078505*pow(x0,2)/(1-pow(x0,2))+12155)/pow(1-pow(x0,2),19.0/2.0)
            case 20:
                derivs[20]=1856156927625*x0*(4418157975*pow(x0,18)/pow(1-pow(x0,2),9)+20419054425*pow(x0,16)/pow(1-pow(x0,2),8)+39671305740*pow(x0,14)/pow(1-pow(x0,2),7)+42075627300*pow(x0,12)/pow(1-pow(x0,2),6)+26466926850*pow(x0,10)/pow(1-pow(x0,2),5)+10039179150*pow(x0,8)/pow(1-pow(x0,2),4)+2230928700*pow(x0,6)/pow(1-pow(x0,2),3)+267711444*pow(x0,4)/pow(1-pow(x0,2),2)+14549535*pow(x0,2)/(1-pow(x0,2))+230945)/pow(1-pow(x0,2),21.0/2.0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_acos(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=acos(x0)
            case 1:
                derivs[1]=-1/sqrt(1-pow(x0,2))
            case 2:
                derivs[2]=-x0/pow(1-pow(x0,2),3.0/2.0)
            case 3:
                derivs[3]=-(3*pow(x0,2)/(1-pow(x0,2))+1)/pow(1-pow(x0,2),3.0/2.0)
            case 4:
                derivs[4]=-3*x0*(5*pow(x0,2)/(1-pow(x0,2))+3)/pow(1-pow(x0,2),5.0/2.0)
            case 5:
                derivs[5]=-3*(35*pow(x0,4)/pow(1-pow(x0,2),2)+30*pow(x0,2)/(1-pow(x0,2))+3)/pow(1-pow(x0,2),5.0/2.0)
            case 6:
                derivs[6]=-15*x0*(63*pow(x0,4)/pow(1-pow(x0,2),2)+70*pow(x0,2)/(1-pow(x0,2))+15)/pow(1-pow(x0,2),7.0/2.0)
            case 7:
                derivs[7]=-45*(231*pow(x0,6)/pow(1-pow(x0,2),3)+315*pow(x0,4)/pow(1-pow(x0,2),2)+105*pow(x0,2)/(1-pow(x0,2))+5)/pow(1-pow(x0,2),7.0/2.0)
            case 8:
                derivs[8]=-315*x0*(429*pow(x0,6)/pow(1-pow(x0,2),3)+693*pow(x0,4)/pow(1-pow(x0,2),2)+315*pow(x0,2)/(1-pow(x0,2))+35)/pow(1-pow(x0,2),9.0/2.0)
            case 9:
                derivs[9]=-315*(6435*pow(x0,8)/pow(1-pow(x0,2),4)+12012*pow(x0,6)/pow(1-pow(x0,2),3)+6930*pow(x0,4)/pow(1-pow(x0,2),2)+1260*pow(x0,2)/(1-pow(x0,2))+35)/pow(1-pow(x0,2),9.0/2.0)
            case 10:
                derivs[10]=-2835*x0*(12155*pow(x0,8)/pow(1-pow(x0,2),4)+25740*pow(x0,6)/pow(1-pow(x0,2),3)+18018*pow(x0,4)/pow(1-pow(x0,2),2)+4620*pow(x0,2)/(1-pow(x0,2))+315)/pow(1-pow(x0,2),11.0/2.0)
            case 11:
                derivs[11]=-14175*(46189*pow(x0,10)/pow(1-pow(x0,2),5)+109395*pow(x0,8)/pow(1-pow(x0,2),4)+90090*pow(x0,6)/pow(1-pow(x0,2),3)+30030*pow(x0,4)/pow(1-pow(x0,2),2)+3465*pow(x0,2)/(1-pow(x0,2))+63)/pow(1-pow(x0,2),11.0/2.0)
            case 12:
                derivs[12]=-155925*x0*(88179*pow(x0,10)/pow(1-pow(x0,2),5)+230945*pow(x0,8)/pow(1-pow(x0,2),4)+218790*pow(x0,6)/pow(1-pow(x0,2),3)+90090*pow(x0,4)/pow(1-pow(x0,2),2)+15015*pow(x0,2)/(1-pow(x0,2))+693)/pow(1-pow(x0,2),13.0/2.0)
            case 13:
                derivs[13]=-467775*(676039*pow(x0,12)/pow(1-pow(x0,2),6)+1939938*pow(x0,10)/pow(1-pow(x0,2),5)+2078505*pow(x0,8)/pow(1-pow(x0,2),4)+1021020*pow(x0,6)/pow(1-pow(x0,2),3)+225225*pow(x0,4)/pow(1-pow(x0,2),2)+18018*pow(x0,2)/(1-pow(x0,2))+231)/pow(1-pow(x0,2),13.0/2.0)
            case 14:
                derivs[14]=-6081075*x0*(1300075*pow(x0,12)/pow(1-pow(x0,2),6)+4056234*pow(x0,10)/pow(1-pow(x0,2),5)+4849845*pow(x0,8)/pow(1-pow(x0,2),4)+2771340*pow(x0,6)/pow(1-pow(x0,2),3)+765765*pow(x0,4)/pow(1-pow(x0,2),2)+90090*pow(x0,2)/(1-pow(x0,2))+3003)/pow(1-pow(x0,2),15.0/2.0)
            case 15:
                derivs[15]=-42567525*(5014575*pow(x0,14)/pow(1-pow(x0,2),7)+16900975*pow(x0,12)/pow(1-pow(x0,2),6)+22309287*pow(x0,10)/pow(1-pow(x0,2),5)+14549535*pow(x0,8)/pow(1-pow(x0,2),4)+4849845*pow(x0,6)/pow(1-pow(x0,2),3)+765765*pow(x0,4)/pow(1-pow(x0,2),2)+45045*pow(x0,2)/(1-pow(x0,2))+429)/pow(1-pow(x0,2),15.0/2.0)
            case 16:
                derivs[16]=-638512875*x0*(9694845*pow(x0,14)/pow(1-pow(x0,2),7)+35102025*pow(x0,12)/pow(1-pow(x0,2),6)+50702925*pow(x0,10)/pow(1-pow(x0,2),5)+37182145*pow(x0,8)/pow(1-pow(x0,2),4)+14549535*pow(x0,6)/pow(1-pow(x0,2),3)+2909907*pow(x0,4)/pow(1-pow(x0,2),2)+255255*pow(x0,2)/(1-pow(x0,2))+6435)/pow(1-pow(x0,2),17.0/2.0)
            case 17:
                derivs[17]=-638512875*(300540195*pow(x0,16)/pow(1-pow(x0,2),8)+1163381400*pow(x0,14)/pow(1-pow(x0,2),7)+1825305300*pow(x0,12)/pow(1-pow(x0,2),6)+1487285800*pow(x0,10)/pow(1-pow(x0,2),5)+669278610*pow(x0,8)/pow(1-pow(x0,2),4)+162954792*pow(x0,6)/pow(1-pow(x0,2),3)+19399380*pow(x0,4)/pow(1-pow(x0,2),2)+875160*pow(x0,2)/(1-pow(x0,2))+6435)/pow(1-pow(x0,2),17.0/2.0)
            case 18:
                derivs[18]=-10854718875*x0*(583401555*pow(x0,16)/pow(1-pow(x0,2),8)+2404321560*pow(x0,14)/pow(1-pow(x0,2),7)+4071834900*pow(x0,12)/pow(1-pow(x0,2),6)+3650610600*pow(x0,10)/pow(1-pow(x0,2),5)+1859107250*pow(x0,8)/pow(1-pow(x0,2),4)+535422888*pow(x0,6)/pow(1-pow(x0,2),3)+81477396*pow(x0,4)/pow(1-pow(x0,2),2)+5542680*pow(x0,2)/(1-pow(x0,2))+109395)/pow(1-pow(x0,2),19.0/2.0)
            case 19:
                derivs[19]=-97692469875*(2268783825*pow(x0,18)/pow(1-pow(x0,2),9)+9917826435*pow(x0,16)/pow(1-pow(x0,2),8)+18032411700*pow(x0,14)/pow(1-pow(x0,2),7)+17644617900*pow(x0,12)/pow(1-pow(x0,2),6)+10039179150*pow(x0,10)/pow(1-pow(x0,2),5)+3346393050*pow(x0,8)/pow(1-pow(x0,2),4)+624660036*pow(x0,6)/pow(1-pow(x0,2),3)+58198140*pow(x0,4)/pow(1-pow(x0,2),2)+2078505*pow(x0,2)/(1-pow(x0,2))+12155)/pow(1-pow(x0,2),19.0/2.0)
            case 20:
                derivs[20]=-1856156927625*x0*(4418157975*pow(x0,18)/pow(1-pow(x0,2),9)+20419054425*pow(x0,16)/pow(1-pow(x0,2),8)+39671305740*pow(x0,14)/pow(1-pow(x0,2),7)+42075627300*pow(x0,12)/pow(1-pow(x0,2),6)+26466926850*pow(x0,10)/pow(1-pow(x0,2),5)+10039179150*pow(x0,8)/pow(1-pow(x0,2),4)+2230928700*pow(x0,6)/pow(1-pow(x0,2),3)+267711444*pow(x0,4)/pow(1-pow(x0,2),2)+14549535*pow(x0,2)/(1-pow(x0,2))+230945)/pow(1-pow(x0,2),21.0/2.0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_atan(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=atan(x0)
            case 1:
                derivs[1]=1.0/(pow(x0,2)+1)
            case 2:
                derivs[2]=-2*x0/pow(pow(x0,2)+1,2)
            case 3:
                derivs[3]=2*(4*pow(x0,2)/(pow(x0,2)+1)-1)/pow(pow(x0,2)+1,2)
            case 4:
                derivs[4]=24*x0*(-2*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,3)
            case 5:
                derivs[5]=24*(16*pow(x0,4)/pow(pow(x0,2)+1,2)-12*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,3)
            case 6:
                derivs[6]=240*x0*(-16*pow(x0,4)/pow(pow(x0,2)+1,2)+16*pow(x0,2)/(pow(x0,2)+1)-3)/pow(pow(x0,2)+1,4)
            case 7:
                derivs[7]=720*(64*pow(x0,6)/pow(pow(x0,2)+1,3)-80*pow(x0,4)/pow(pow(x0,2)+1,2)+24*pow(x0,2)/(pow(x0,2)+1)-1)/pow(pow(x0,2)+1,4)
            case 8:
                derivs[8]=40320*x0*(-16*pow(x0,6)/pow(pow(x0,2)+1,3)+24*pow(x0,4)/pow(pow(x0,2)+1,2)-10*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,5)
            case 9:
                derivs[9]=40320*(256*pow(x0,8)/pow(pow(x0,2)+1,4)-448*pow(x0,6)/pow(pow(x0,2)+1,3)+240*pow(x0,4)/pow(pow(x0,2)+1,2)-40*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,5)
            case 10:
                derivs[10]=725760*x0*(-256*pow(x0,8)/pow(pow(x0,2)+1,4)+512*pow(x0,6)/pow(pow(x0,2)+1,3)-336*pow(x0,4)/pow(pow(x0,2)+1,2)+80*pow(x0,2)/(pow(x0,2)+1)-5)/pow(pow(x0,2)+1,6)
            case 11:
                derivs[11]=3628800*(1024*pow(x0,10)/pow(pow(x0,2)+1,5)-2304*pow(x0,8)/pow(pow(x0,2)+1,4)+1792*pow(x0,6)/pow(pow(x0,2)+1,3)-560*pow(x0,4)/pow(pow(x0,2)+1,2)+60*pow(x0,2)/(pow(x0,2)+1)-1)/pow(pow(x0,2)+1,6)
            case 12:
                derivs[12]=159667200*x0*(-512*pow(x0,10)/pow(pow(x0,2)+1,5)+1280*pow(x0,8)/pow(pow(x0,2)+1,4)-1152*pow(x0,6)/pow(pow(x0,2)+1,3)+448*pow(x0,4)/pow(pow(x0,2)+1,2)-70*pow(x0,2)/(pow(x0,2)+1)+3)/pow(pow(x0,2)+1,7)
            case 13:
                derivs[13]=479001600*(4096*pow(x0,12)/pow(pow(x0,2)+1,6)-11264*pow(x0,10)/pow(pow(x0,2)+1,5)+11520*pow(x0,8)/pow(pow(x0,2)+1,4)-5376*pow(x0,6)/pow(pow(x0,2)+1,3)+1120*pow(x0,4)/pow(pow(x0,2)+1,2)-84*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,7)
            case 14:
                derivs[14]=12454041600*x0*(-4096*pow(x0,12)/pow(pow(x0,2)+1,6)+12288*pow(x0,10)/pow(pow(x0,2)+1,5)-14080*pow(x0,8)/pow(pow(x0,2)+1,4)+7680*pow(x0,6)/pow(pow(x0,2)+1,3)-2016*pow(x0,4)/pow(pow(x0,2)+1,2)+224*pow(x0,2)/(pow(x0,2)+1)-7)/pow(pow(x0,2)+1,8)
            case 15:
                derivs[15]=87178291200*(16384*pow(x0,14)/pow(pow(x0,2)+1,7)-53248*pow(x0,12)/pow(pow(x0,2)+1,6)+67584*pow(x0,10)/pow(pow(x0,2)+1,5)-42240*pow(x0,8)/pow(pow(x0,2)+1,4)+13440*pow(x0,6)/pow(pow(x0,2)+1,3)-2016*pow(x0,4)/pow(pow(x0,2)+1,2)+112*pow(x0,2)/(pow(x0,2)+1)-1)/pow(pow(x0,2)+1,8)
            case 16:
                derivs[16]=20922789888000*x0*(-2048*pow(x0,14)/pow(pow(x0,2)+1,7)+7168*pow(x0,12)/pow(pow(x0,2)+1,6)-9984*pow(x0,10)/pow(pow(x0,2)+1,5)+7040*pow(x0,8)/pow(pow(x0,2)+1,4)-2640*pow(x0,6)/pow(pow(x0,2)+1,3)+504*pow(x0,4)/pow(pow(x0,2)+1,2)-42*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,9)
            case 17:
                derivs[17]=20922789888000*(65536*pow(x0,16)/pow(pow(x0,2)+1,8)-245760*pow(x0,14)/pow(pow(x0,2)+1,7)+372736*pow(x0,12)/pow(pow(x0,2)+1,6)-292864*pow(x0,10)/pow(pow(x0,2)+1,5)+126720*pow(x0,8)/pow(pow(x0,2)+1,4)-29568*pow(x0,6)/pow(pow(x0,2)+1,3)+3360*pow(x0,4)/pow(pow(x0,2)+1,2)-144*pow(x0,2)/(pow(x0,2)+1)+1)/pow(pow(x0,2)+1,9)
            case 18:
                derivs[18]=711374856192000*x0*(-65536*pow(x0,16)/pow(pow(x0,2)+1,8)+262144*pow(x0,14)/pow(pow(x0,2)+1,7)-430080*pow(x0,12)/pow(pow(x0,2)+1,6)+372736*pow(x0,10)/pow(pow(x0,2)+1,5)-183040*pow(x0,8)/pow(pow(x0,2)+1,4)+50688*pow(x0,6)/pow(pow(x0,2)+1,3)-7392*pow(x0,4)/pow(pow(x0,2)+1,2)+480*pow(x0,2)/(pow(x0,2)+1)-9)/pow(pow(x0,2)+1,10)
            case 19:
                derivs[19]=6402373705728000*(262144*pow(x0,18)/pow(pow(x0,2)+1,9)-1114112*pow(x0,16)/pow(pow(x0,2)+1,8)+1966080*pow(x0,14)/pow(pow(x0,2)+1,7)-1863680*pow(x0,12)/pow(pow(x0,2)+1,6)+1025024*pow(x0,10)/pow(pow(x0,2)+1,5)-329472*pow(x0,8)/pow(pow(x0,2)+1,4)+59136*pow(x0,6)/pow(pow(x0,2)+1,3)-5280*pow(x0,4)/pow(pow(x0,2)+1,2)+180*pow(x0,2)/(pow(x0,2)+1)-1)/pow(pow(x0,2)+1,10)
            case 20:
                derivs[20]=486580401635328000*x0*(-131072*pow(x0,18)/pow(pow(x0,2)+1,9)+589824*pow(x0,16)/pow(pow(x0,2)+1,8)-1114112*pow(x0,14)/pow(pow(x0,2)+1,7)+1146880*pow(x0,12)/pow(pow(x0,2)+1,6)-698880*pow(x0,10)/pow(pow(x0,2)+1,5)+256256*pow(x0,8)/pow(pow(x0,2)+1,4)-54912*pow(x0,6)/pow(pow(x0,2)+1,3)+6336*pow(x0,4)/pow(pow(x0,2)+1,2)-330*pow(x0,2)/(pow(x0,2)+1)+5)/pow(pow(x0,2)+1,11)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_log(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=log(x0)
            case 1:
                derivs[1]=1.0/x0
            case 2:
                derivs[2]=-1/pow(x0,2)
            case 3:
                derivs[3]=2/pow(x0,3)
            case 4:
                derivs[4]=-6/pow(x0,4)
            case 5:
                derivs[5]=24/pow(x0,5)
            case 6:
                derivs[6]=-120/pow(x0,6)
            case 7:
                derivs[7]=720/pow(x0,7)
            case 8:
                derivs[8]=-5040/pow(x0,8)
            case 9:
                derivs[9]=40320/pow(x0,9)
            case 10:
                derivs[10]=-362880/pow(x0,10)
            case 11:
                derivs[11]=3628800/pow(x0,11)
            case 12:
                derivs[12]=-39916800/pow(x0,12)
            case 13:
                derivs[13]=479001600/pow(x0,13)
            case 14:
                derivs[14]=-6227020800/pow(x0,14)
            case 15:
                derivs[15]=87178291200/pow(x0,15)
            case 16:
                derivs[16]=-1307674368000/pow(x0,16)
            case 17:
                derivs[17]=20922789888000/pow(x0,17)
            case 18:
                derivs[18]=-355687428096000/pow(x0,18)
            case 19:
                derivs[19]=6402373705728000/pow(x0,19)
            case 20:
                derivs[20]=-121645100408832000/pow(x0,20)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_exp(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=exp(x0)
            case 1:
                derivs[1]=exp(x0)
            case 2:
                derivs[2]=exp(x0)
            case 3:
                derivs[3]=exp(x0)
            case 4:
                derivs[4]=exp(x0)
            case 5:
                derivs[5]=exp(x0)
            case 6:
                derivs[6]=exp(x0)
            case 7:
                derivs[7]=exp(x0)
            case 8:
                derivs[8]=exp(x0)
            case 9:
                derivs[9]=exp(x0)
            case 10:
                derivs[10]=exp(x0)
            case 11:
                derivs[11]=exp(x0)
            case 12:
                derivs[12]=exp(x0)
            case 13:
                derivs[13]=exp(x0)
            case 14:
                derivs[14]=exp(x0)
            case 15:
                derivs[15]=exp(x0)
            case 16:
                derivs[16]=exp(x0)
            case 17:
                derivs[17]=exp(x0)
            case 18:
                derivs[18]=exp(x0)
            case 19:
                derivs[19]=exp(x0)
            case 20:
                derivs[20]=exp(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_sinh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=sinh(x0)
            case 1:
                derivs[1]=cosh(x0)
            case 2:
                derivs[2]=sinh(x0)
            case 3:
                derivs[3]=cosh(x0)
            case 4:
                derivs[4]=sinh(x0)
            case 5:
                derivs[5]=cosh(x0)
            case 6:
                derivs[6]=sinh(x0)
            case 7:
                derivs[7]=cosh(x0)
            case 8:
                derivs[8]=sinh(x0)
            case 9:
                derivs[9]=cosh(x0)
            case 10:
                derivs[10]=sinh(x0)
            case 11:
                derivs[11]=cosh(x0)
            case 12:
                derivs[12]=sinh(x0)
            case 13:
                derivs[13]=cosh(x0)
            case 14:
                derivs[14]=sinh(x0)
            case 15:
                derivs[15]=cosh(x0)
            case 16:
                derivs[16]=sinh(x0)
            case 17:
                derivs[17]=cosh(x0)
            case 18:
                derivs[18]=sinh(x0)
            case 19:
                derivs[19]=cosh(x0)
            case 20:
                derivs[20]=sinh(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_cosh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=cosh(x0)
            case 1:
                derivs[1]=sinh(x0)
            case 2:
                derivs[2]=cosh(x0)
            case 3:
                derivs[3]=sinh(x0)
            case 4:
                derivs[4]=cosh(x0)
            case 5:
                derivs[5]=sinh(x0)
            case 6:
                derivs[6]=cosh(x0)
            case 7:
                derivs[7]=sinh(x0)
            case 8:
                derivs[8]=cosh(x0)
            case 9:
                derivs[9]=sinh(x0)
            case 10:
                derivs[10]=cosh(x0)
            case 11:
                derivs[11]=sinh(x0)
            case 12:
                derivs[12]=cosh(x0)
            case 13:
                derivs[13]=sinh(x0)
            case 14:
                derivs[14]=cosh(x0)
            case 15:
                derivs[15]=sinh(x0)
            case 16:
                derivs[16]=cosh(x0)
            case 17:
                derivs[17]=sinh(x0)
            case 18:
                derivs[18]=cosh(x0)
            case 19:
                derivs[19]=sinh(x0)
            case 20:
                derivs[20]=cosh(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_tanh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=tanh(x0)
            case 1:
                derivs[1]=1-pow(tanh(x0),2)
            case 2:
                derivs[2]=2*(pow(tanh(x0),2)-1)*tanh(x0)
            case 3:
                derivs[3]=-2*(pow(tanh(x0),2)-1)*(3*pow(tanh(x0),2)-1)
            case 4:
                derivs[4]=8*(pow(tanh(x0),2)-1)*(3*pow(tanh(x0),2)-2)*tanh(x0)
            case 5:
                derivs[5]=-8*(pow(tanh(x0),2)-1)*(2*pow(pow(tanh(x0),2)-1,2)+11*(pow(tanh(x0),2)-1)*pow(tanh(x0),2)+2*pow(tanh(x0),4))
            case 6:
                derivs[6]=16*(pow(tanh(x0),2)-1)*(17*pow(pow(tanh(x0),2)-1,2)+26*(pow(tanh(x0),2)-1)*pow(tanh(x0),2)+2*pow(tanh(x0),4))*tanh(x0)
            case 7:
                derivs[7]=-16*(pow(tanh(x0),2)-1)*(17*pow(pow(tanh(x0),2)-1,3)+180*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),2)+114*(pow(tanh(x0),2)-1)*pow(tanh(x0),4)+4*pow(tanh(x0),6))
            case 8:
                derivs[8]=128*(pow(tanh(x0),2)-1)*(62*pow(pow(tanh(x0),2)-1,3)+192*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),2)+60*(pow(tanh(x0),2)-1)*pow(tanh(x0),4)+pow(tanh(x0),6))*tanh(x0)
            case 9:
                derivs[9]=-128*(pow(tanh(x0),2)-1)*(62*pow(pow(tanh(x0),2)-1,4)+1072*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),2)+1452*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),4)+247*(pow(tanh(x0),2)-1)*pow(tanh(x0),6)+2*pow(tanh(x0),8))
            case 10:
                derivs[10]=256*(pow(tanh(x0),2)-1)*(1382*pow(pow(tanh(x0),2)-1,4)+7192*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),2)+5097*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),4)+502*(pow(tanh(x0),2)-1)*pow(tanh(x0),6)+2*pow(tanh(x0),8))*tanh(x0)
            case 11:
                derivs[11]=-256*(pow(tanh(x0),2)-1)*(1382*pow(pow(tanh(x0),2)-1,5)+35396*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),2)+83021*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),4)+34096*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),6)+2026*(pow(tanh(x0),2)-1)*pow(tanh(x0),8)+4*pow(tanh(x0),10))
            case 12:
                derivs[12]=1024*(pow(tanh(x0),2)-1)*(21844*pow(pow(tanh(x0),2)-1,5)+171511*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),2)+217186*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),4)+55196*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),6)+2036*(pow(tanh(x0),2)-1)*pow(tanh(x0),8)+2*pow(tanh(x0),10))*tanh(x0)
            case 13:
                derivs[13]=-1024*(pow(tanh(x0),2)-1)*(21844*pow(pow(tanh(x0),2)-1,6)+776661*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),2)+2801040*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),4)+2123860*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),6)+349500*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),8)+8166*(pow(tanh(x0),2)-1)*pow(tanh(x0),10)+4*pow(tanh(x0),12))
            case 14:
                derivs[14]=2048*(pow(tanh(x0),2)-1)*(929569*pow(pow(tanh(x0),2)-1,6)+10262046*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),2)+20376780*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),4)+9893440*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),6)+1089330*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),8)+16356*(pow(tanh(x0),2)-1)*pow(tanh(x0),10)+4*pow(tanh(x0),12))*tanh(x0)
            case 15:
                derivs[15]=-2048*(pow(tanh(x0),2)-1)*(929569*pow(pow(tanh(x0),2)-1,7)+43800104*pow(pow(tanh(x0),2)-1,6)*pow(tanh(x0),2)+225028452*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),4)+273021880*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),6)+88951490*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),8)+6715896*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),10)+65476*(pow(tanh(x0),2)-1)*pow(tanh(x0),12)+8*pow(tanh(x0),14))
            case 16:
                derivs[16]=32768*(pow(tanh(x0),2)-1)*(6404582*pow(pow(tanh(x0),2)-1,7)+94582204*pow(pow(tanh(x0),2)-1,6)*pow(tanh(x0),2)+271154544*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),4)+215114420*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),6)+48673180*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),8)+2567568*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),10)+16376*(pow(tanh(x0),2)-1)*pow(tanh(x0),12)+pow(tanh(x0),14))*tanh(x0)
            case 17:
                derivs[17]=-32768*(pow(tanh(x0),2)-1)*(6404582*pow(pow(tanh(x0),2)-1,8)+386219924*pow(pow(tanh(x0),2)-1,7)*pow(tanh(x0),2)+2679923576*pow(pow(tanh(x0),2)-1,6)*pow(tanh(x0),4)+4759655468*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),6)+2589202820*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),8)+417628688*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),10)+15618296*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),12)+65519*(pow(tanh(x0),2)-1)*pow(tanh(x0),14)+2*pow(tanh(x0),16))
            case 18:
                derivs[18]=65536*(pow(tanh(x0),2)-1)*(443861162*pow(pow(tanh(x0),2)-1,8)+8449606544*pow(pow(tanh(x0),2)-1,7)*pow(tanh(x0),2)+33038431436*pow(pow(tanh(x0),2)-1,6)*pow(tanh(x0),4)+38914744088*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),6)+15034157540*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),8)+1764224528*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),10)+47313521*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),12)+131054*(pow(tanh(x0),2)-1)*pow(tanh(x0),14)+2*pow(tanh(x0),16))*tanh(x0)
            case 19:
                derivs[19]=-65536*(pow(tanh(x0),2)-1)*(443861162*pow(pow(tanh(x0),2)-1,9)+33338320548*pow(pow(tanh(x0),2)-1,8)*pow(tanh(x0),2)+300385861884*pow(pow(tanh(x0),2)-1,7)*pow(tanh(x0),4)+734941248720*pow(pow(tanh(x0),2)-1,6)*pow(tanh(x0),6)+602284346916*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),8)+169748045208*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),10)+14728871997*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),12)+285846936*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),14)+524250*(pow(tanh(x0),2)-1)*pow(tanh(x0),16)+4*pow(tanh(x0),18))
            case 20:
                derivs[20]=262144*(pow(tanh(x0),2)-1)*(18888466084*pow(pow(tanh(x0),2)-1,9)+450408304350*pow(pow(tanh(x0),2)-1,8)*pow(tanh(x0),2)+2303955320616*pow(pow(tanh(x0),2)-1,7)*pow(tanh(x0),4)+3776863064352*pow(pow(tanh(x0),2)-1,6)*pow(tanh(x0),6)+2231223153768*pow(pow(tanh(x0),2)-1,5)*pow(tanh(x0),8)+468556729011*pow(pow(tanh(x0),2)-1,4)*pow(tanh(x0),10)+30458208270*pow(pow(tanh(x0),2)-1,3)*pow(tanh(x0),12)+430867404*pow(pow(tanh(x0),2)-1,2)*pow(tanh(x0),14)+524268*(pow(tanh(x0),2)-1)*pow(tanh(x0),16)+2*pow(tanh(x0),18))*tanh(x0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_asinh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=asinh(x0)
            case 1:
                derivs[1]=pow(pow(x0,2)+1,-1.0/2.0)
            case 2:
                derivs[2]=-x0/pow(pow(x0,2)+1,3.0/2.0)
            case 3:
                derivs[3]=(3*pow(x0,2)/(pow(x0,2)+1)-1)/pow(pow(x0,2)+1,3.0/2.0)
            case 4:
                derivs[4]=3*x0*(-5*pow(x0,2)/(pow(x0,2)+1)+3)/pow(pow(x0,2)+1,5.0/2.0)
            case 5:
                derivs[5]=3*(35*pow(x0,4)/pow(pow(x0,2)+1,2)-30*pow(x0,2)/(pow(x0,2)+1)+3)/pow(pow(x0,2)+1,5.0/2.0)
            case 6:
                derivs[6]=15*x0*(-63*pow(x0,4)/pow(pow(x0,2)+1,2)+70*pow(x0,2)/(pow(x0,2)+1)-15)/pow(pow(x0,2)+1,7.0/2.0)
            case 7:
                derivs[7]=45*(231*pow(x0,6)/pow(pow(x0,2)+1,3)-315*pow(x0,4)/pow(pow(x0,2)+1,2)+105*pow(x0,2)/(pow(x0,2)+1)-5)/pow(pow(x0,2)+1,7.0/2.0)
            case 8:
                derivs[8]=315*x0*(-429*pow(x0,6)/pow(pow(x0,2)+1,3)+693*pow(x0,4)/pow(pow(x0,2)+1,2)-315*pow(x0,2)/(pow(x0,2)+1)+35)/pow(pow(x0,2)+1,9.0/2.0)
            case 9:
                derivs[9]=315*(6435*pow(x0,8)/pow(pow(x0,2)+1,4)-12012*pow(x0,6)/pow(pow(x0,2)+1,3)+6930*pow(x0,4)/pow(pow(x0,2)+1,2)-1260*pow(x0,2)/(pow(x0,2)+1)+35)/pow(pow(x0,2)+1,9.0/2.0)
            case 10:
                derivs[10]=2835*x0*(-12155*pow(x0,8)/pow(pow(x0,2)+1,4)+25740*pow(x0,6)/pow(pow(x0,2)+1,3)-18018*pow(x0,4)/pow(pow(x0,2)+1,2)+4620*pow(x0,2)/(pow(x0,2)+1)-315)/pow(pow(x0,2)+1,11.0/2.0)
            case 11:
                derivs[11]=14175*(46189*pow(x0,10)/pow(pow(x0,2)+1,5)-109395*pow(x0,8)/pow(pow(x0,2)+1,4)+90090*pow(x0,6)/pow(pow(x0,2)+1,3)-30030*pow(x0,4)/pow(pow(x0,2)+1,2)+3465*pow(x0,2)/(pow(x0,2)+1)-63)/pow(pow(x0,2)+1,11.0/2.0)
            case 12:
                derivs[12]=155925*x0*(-88179*pow(x0,10)/pow(pow(x0,2)+1,5)+230945*pow(x0,8)/pow(pow(x0,2)+1,4)-218790*pow(x0,6)/pow(pow(x0,2)+1,3)+90090*pow(x0,4)/pow(pow(x0,2)+1,2)-15015*pow(x0,2)/(pow(x0,2)+1)+693)/pow(pow(x0,2)+1,13.0/2.0)
            case 13:
                derivs[13]=467775*(676039*pow(x0,12)/pow(pow(x0,2)+1,6)-1939938*pow(x0,10)/pow(pow(x0,2)+1,5)+2078505*pow(x0,8)/pow(pow(x0,2)+1,4)-1021020*pow(x0,6)/pow(pow(x0,2)+1,3)+225225*pow(x0,4)/pow(pow(x0,2)+1,2)-18018*pow(x0,2)/(pow(x0,2)+1)+231)/pow(pow(x0,2)+1,13.0/2.0)
            case 14:
                derivs[14]=6081075*x0*(-1300075*pow(x0,12)/pow(pow(x0,2)+1,6)+4056234*pow(x0,10)/pow(pow(x0,2)+1,5)-4849845*pow(x0,8)/pow(pow(x0,2)+1,4)+2771340*pow(x0,6)/pow(pow(x0,2)+1,3)-765765*pow(x0,4)/pow(pow(x0,2)+1,2)+90090*pow(x0,2)/(pow(x0,2)+1)-3003)/pow(pow(x0,2)+1,15.0/2.0)
            case 15:
                derivs[15]=42567525*(5014575*pow(x0,14)/pow(pow(x0,2)+1,7)-16900975*pow(x0,12)/pow(pow(x0,2)+1,6)+22309287*pow(x0,10)/pow(pow(x0,2)+1,5)-14549535*pow(x0,8)/pow(pow(x0,2)+1,4)+4849845*pow(x0,6)/pow(pow(x0,2)+1,3)-765765*pow(x0,4)/pow(pow(x0,2)+1,2)+45045*pow(x0,2)/(pow(x0,2)+1)-429)/pow(pow(x0,2)+1,15.0/2.0)
            case 16:
                derivs[16]=638512875*x0*(-9694845*pow(x0,14)/pow(pow(x0,2)+1,7)+35102025*pow(x0,12)/pow(pow(x0,2)+1,6)-50702925*pow(x0,10)/pow(pow(x0,2)+1,5)+37182145*pow(x0,8)/pow(pow(x0,2)+1,4)-14549535*pow(x0,6)/pow(pow(x0,2)+1,3)+2909907*pow(x0,4)/pow(pow(x0,2)+1,2)-255255*pow(x0,2)/(pow(x0,2)+1)+6435)/pow(pow(x0,2)+1,17.0/2.0)
            case 17:
                derivs[17]=638512875*(300540195*pow(x0,16)/pow(pow(x0,2)+1,8)-1163381400*pow(x0,14)/pow(pow(x0,2)+1,7)+1825305300*pow(x0,12)/pow(pow(x0,2)+1,6)-1487285800*pow(x0,10)/pow(pow(x0,2)+1,5)+669278610*pow(x0,8)/pow(pow(x0,2)+1,4)-162954792*pow(x0,6)/pow(pow(x0,2)+1,3)+19399380*pow(x0,4)/pow(pow(x0,2)+1,2)-875160*pow(x0,2)/(pow(x0,2)+1)+6435)/pow(pow(x0,2)+1,17.0/2.0)
            case 18:
                derivs[18]=10854718875*x0*(-583401555*pow(x0,16)/pow(pow(x0,2)+1,8)+2404321560*pow(x0,14)/pow(pow(x0,2)+1,7)-4071834900*pow(x0,12)/pow(pow(x0,2)+1,6)+3650610600*pow(x0,10)/pow(pow(x0,2)+1,5)-1859107250*pow(x0,8)/pow(pow(x0,2)+1,4)+535422888*pow(x0,6)/pow(pow(x0,2)+1,3)-81477396*pow(x0,4)/pow(pow(x0,2)+1,2)+5542680*pow(x0,2)/(pow(x0,2)+1)-109395)/pow(pow(x0,2)+1,19.0/2.0)
            case 19:
                derivs[19]=97692469875*(2268783825*pow(x0,18)/pow(pow(x0,2)+1,9)-9917826435*pow(x0,16)/pow(pow(x0,2)+1,8)+18032411700*pow(x0,14)/pow(pow(x0,2)+1,7)-17644617900*pow(x0,12)/pow(pow(x0,2)+1,6)+10039179150*pow(x0,10)/pow(pow(x0,2)+1,5)-3346393050*pow(x0,8)/pow(pow(x0,2)+1,4)+624660036*pow(x0,6)/pow(pow(x0,2)+1,3)-58198140*pow(x0,4)/pow(pow(x0,2)+1,2)+2078505*pow(x0,2)/(pow(x0,2)+1)-12155)/pow(pow(x0,2)+1,19.0/2.0)
            case 20:
                derivs[20]=1856156927625*x0*(-4418157975*pow(x0,18)/pow(pow(x0,2)+1,9)+20419054425*pow(x0,16)/pow(pow(x0,2)+1,8)-39671305740*pow(x0,14)/pow(pow(x0,2)+1,7)+42075627300*pow(x0,12)/pow(pow(x0,2)+1,6)-26466926850*pow(x0,10)/pow(pow(x0,2)+1,5)+10039179150*pow(x0,8)/pow(pow(x0,2)+1,4)-2230928700*pow(x0,6)/pow(pow(x0,2)+1,3)+267711444*pow(x0,4)/pow(pow(x0,2)+1,2)-14549535*pow(x0,2)/(pow(x0,2)+1)+230945)/pow(pow(x0,2)+1,21.0/2.0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_acosh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=acosh(x0)
            case 1:
                derivs[1]=pow(pow(x0,2)-1,-1.0/2.0)
            case 2:
                derivs[2]=-x0/pow(pow(x0,2)-1,3.0/2.0)
            case 3:
                derivs[3]=(3*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,3.0/2.0)
            case 4:
                derivs[4]=3*x0*(-5*pow(x0,2)/(pow(x0,2)-1)+3)/pow(pow(x0,2)-1,5.0/2.0)
            case 5:
                derivs[5]=3*(35*pow(x0,4)/pow(pow(x0,2)-1,2)-30*pow(x0,2)/(pow(x0,2)-1)+3)/pow(pow(x0,2)-1,5.0/2.0)
            case 6:
                derivs[6]=15*x0*(-63*pow(x0,4)/pow(pow(x0,2)-1,2)+70*pow(x0,2)/(pow(x0,2)-1)-15)/pow(pow(x0,2)-1,7.0/2.0)
            case 7:
                derivs[7]=45*(231*pow(x0,6)/pow(pow(x0,2)-1,3)-315*pow(x0,4)/pow(pow(x0,2)-1,2)+105*pow(x0,2)/(pow(x0,2)-1)-5)/pow(pow(x0,2)-1,7.0/2.0)
            case 8:
                derivs[8]=315*x0*(-429*pow(x0,6)/pow(pow(x0,2)-1,3)+693*pow(x0,4)/pow(pow(x0,2)-1,2)-315*pow(x0,2)/(pow(x0,2)-1)+35)/pow(pow(x0,2)-1,9.0/2.0)
            case 9:
                derivs[9]=315*(6435*pow(x0,8)/pow(pow(x0,2)-1,4)-12012*pow(x0,6)/pow(pow(x0,2)-1,3)+6930*pow(x0,4)/pow(pow(x0,2)-1,2)-1260*pow(x0,2)/(pow(x0,2)-1)+35)/pow(pow(x0,2)-1,9.0/2.0)
            case 10:
                derivs[10]=2835*x0*(-12155*pow(x0,8)/pow(pow(x0,2)-1,4)+25740*pow(x0,6)/pow(pow(x0,2)-1,3)-18018*pow(x0,4)/pow(pow(x0,2)-1,2)+4620*pow(x0,2)/(pow(x0,2)-1)-315)/pow(pow(x0,2)-1,11.0/2.0)
            case 11:
                derivs[11]=14175*(46189*pow(x0,10)/pow(pow(x0,2)-1,5)-109395*pow(x0,8)/pow(pow(x0,2)-1,4)+90090*pow(x0,6)/pow(pow(x0,2)-1,3)-30030*pow(x0,4)/pow(pow(x0,2)-1,2)+3465*pow(x0,2)/(pow(x0,2)-1)-63)/pow(pow(x0,2)-1,11.0/2.0)
            case 12:
                derivs[12]=155925*x0*(-88179*pow(x0,10)/pow(pow(x0,2)-1,5)+230945*pow(x0,8)/pow(pow(x0,2)-1,4)-218790*pow(x0,6)/pow(pow(x0,2)-1,3)+90090*pow(x0,4)/pow(pow(x0,2)-1,2)-15015*pow(x0,2)/(pow(x0,2)-1)+693)/pow(pow(x0,2)-1,13.0/2.0)
            case 13:
                derivs[13]=467775*(676039*pow(x0,12)/pow(pow(x0,2)-1,6)-1939938*pow(x0,10)/pow(pow(x0,2)-1,5)+2078505*pow(x0,8)/pow(pow(x0,2)-1,4)-1021020*pow(x0,6)/pow(pow(x0,2)-1,3)+225225*pow(x0,4)/pow(pow(x0,2)-1,2)-18018*pow(x0,2)/(pow(x0,2)-1)+231)/pow(pow(x0,2)-1,13.0/2.0)
            case 14:
                derivs[14]=6081075*x0*(-1300075*pow(x0,12)/pow(pow(x0,2)-1,6)+4056234*pow(x0,10)/pow(pow(x0,2)-1,5)-4849845*pow(x0,8)/pow(pow(x0,2)-1,4)+2771340*pow(x0,6)/pow(pow(x0,2)-1,3)-765765*pow(x0,4)/pow(pow(x0,2)-1,2)+90090*pow(x0,2)/(pow(x0,2)-1)-3003)/pow(pow(x0,2)-1,15.0/2.0)
            case 15:
                derivs[15]=42567525*(5014575*pow(x0,14)/pow(pow(x0,2)-1,7)-16900975*pow(x0,12)/pow(pow(x0,2)-1,6)+22309287*pow(x0,10)/pow(pow(x0,2)-1,5)-14549535*pow(x0,8)/pow(pow(x0,2)-1,4)+4849845*pow(x0,6)/pow(pow(x0,2)-1,3)-765765*pow(x0,4)/pow(pow(x0,2)-1,2)+45045*pow(x0,2)/(pow(x0,2)-1)-429)/pow(pow(x0,2)-1,15.0/2.0)
            case 16:
                derivs[16]=638512875*x0*(-9694845*pow(x0,14)/pow(pow(x0,2)-1,7)+35102025*pow(x0,12)/pow(pow(x0,2)-1,6)-50702925*pow(x0,10)/pow(pow(x0,2)-1,5)+37182145*pow(x0,8)/pow(pow(x0,2)-1,4)-14549535*pow(x0,6)/pow(pow(x0,2)-1,3)+2909907*pow(x0,4)/pow(pow(x0,2)-1,2)-255255*pow(x0,2)/(pow(x0,2)-1)+6435)/pow(pow(x0,2)-1,17.0/2.0)
            case 17:
                derivs[17]=638512875*(300540195*pow(x0,16)/pow(pow(x0,2)-1,8)-1163381400*pow(x0,14)/pow(pow(x0,2)-1,7)+1825305300*pow(x0,12)/pow(pow(x0,2)-1,6)-1487285800*pow(x0,10)/pow(pow(x0,2)-1,5)+669278610*pow(x0,8)/pow(pow(x0,2)-1,4)-162954792*pow(x0,6)/pow(pow(x0,2)-1,3)+19399380*pow(x0,4)/pow(pow(x0,2)-1,2)-875160*pow(x0,2)/(pow(x0,2)-1)+6435)/pow(pow(x0,2)-1,17.0/2.0)
            case 18:
                derivs[18]=10854718875*x0*(-583401555*pow(x0,16)/pow(pow(x0,2)-1,8)+2404321560*pow(x0,14)/pow(pow(x0,2)-1,7)-4071834900*pow(x0,12)/pow(pow(x0,2)-1,6)+3650610600*pow(x0,10)/pow(pow(x0,2)-1,5)-1859107250*pow(x0,8)/pow(pow(x0,2)-1,4)+535422888*pow(x0,6)/pow(pow(x0,2)-1,3)-81477396*pow(x0,4)/pow(pow(x0,2)-1,2)+5542680*pow(x0,2)/(pow(x0,2)-1)-109395)/pow(pow(x0,2)-1,19.0/2.0)
            case 19:
                derivs[19]=97692469875*(2268783825*pow(x0,18)/pow(pow(x0,2)-1,9)-9917826435*pow(x0,16)/pow(pow(x0,2)-1,8)+18032411700*pow(x0,14)/pow(pow(x0,2)-1,7)-17644617900*pow(x0,12)/pow(pow(x0,2)-1,6)+10039179150*pow(x0,10)/pow(pow(x0,2)-1,5)-3346393050*pow(x0,8)/pow(pow(x0,2)-1,4)+624660036*pow(x0,6)/pow(pow(x0,2)-1,3)-58198140*pow(x0,4)/pow(pow(x0,2)-1,2)+2078505*pow(x0,2)/(pow(x0,2)-1)-12155)/pow(pow(x0,2)-1,19.0/2.0)
            case 20:
                derivs[20]=1856156927625*x0*(-4418157975*pow(x0,18)/pow(pow(x0,2)-1,9)+20419054425*pow(x0,16)/pow(pow(x0,2)-1,8)-39671305740*pow(x0,14)/pow(pow(x0,2)-1,7)+42075627300*pow(x0,12)/pow(pow(x0,2)-1,6)-26466926850*pow(x0,10)/pow(pow(x0,2)-1,5)+10039179150*pow(x0,8)/pow(pow(x0,2)-1,4)-2230928700*pow(x0,6)/pow(pow(x0,2)-1,3)+267711444*pow(x0,4)/pow(pow(x0,2)-1,2)-14549535*pow(x0,2)/(pow(x0,2)-1)+230945)/pow(pow(x0,2)-1,21.0/2.0)
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_atanh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    for(i=0;i<=order;i++){
        switch(i){
            case 0:
                derivs[0]=atanh(x0)
            case 1:
                derivs[1]=1.0/(1-pow(x0,2))
            case 2:
                derivs[2]=2*x0/pow(pow(x0,2)-1,2)
            case 3:
                derivs[3]=2*(-4*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,2)
            case 4:
                derivs[4]=24*x0*(2*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,3)
            case 5:
                derivs[5]=24*(-16*pow(x0,4)/pow(pow(x0,2)-1,2)+12*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,3)
            case 6:
                derivs[6]=240*x0*(16*pow(x0,4)/pow(pow(x0,2)-1,2)-16*pow(x0,2)/(pow(x0,2)-1)+3)/pow(pow(x0,2)-1,4)
            case 7:
                derivs[7]=720*(-64*pow(x0,6)/pow(pow(x0,2)-1,3)+80*pow(x0,4)/pow(pow(x0,2)-1,2)-24*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,4)
            case 8:
                derivs[8]=40320*x0*(16*pow(x0,6)/pow(pow(x0,2)-1,3)-24*pow(x0,4)/pow(pow(x0,2)-1,2)+10*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,5)
            case 9:
                derivs[9]=40320*(-256*pow(x0,8)/pow(pow(x0,2)-1,4)+448*pow(x0,6)/pow(pow(x0,2)-1,3)-240*pow(x0,4)/pow(pow(x0,2)-1,2)+40*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,5)
            case 10:
                derivs[10]=725760*x0*(256*pow(x0,8)/pow(pow(x0,2)-1,4)-512*pow(x0,6)/pow(pow(x0,2)-1,3)+336*pow(x0,4)/pow(pow(x0,2)-1,2)-80*pow(x0,2)/(pow(x0,2)-1)+5)/pow(pow(x0,2)-1,6)
            case 11:
                derivs[11]=3628800*(-1024*pow(x0,10)/pow(pow(x0,2)-1,5)+2304*pow(x0,8)/pow(pow(x0,2)-1,4)-1792*pow(x0,6)/pow(pow(x0,2)-1,3)+560*pow(x0,4)/pow(pow(x0,2)-1,2)-60*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,6)
            case 12:
                derivs[12]=159667200*x0*(512*pow(x0,10)/pow(pow(x0,2)-1,5)-1280*pow(x0,8)/pow(pow(x0,2)-1,4)+1152*pow(x0,6)/pow(pow(x0,2)-1,3)-448*pow(x0,4)/pow(pow(x0,2)-1,2)+70*pow(x0,2)/(pow(x0,2)-1)-3)/pow(pow(x0,2)-1,7)
            case 13:
                derivs[13]=479001600*(-4096*pow(x0,12)/pow(pow(x0,2)-1,6)+11264*pow(x0,10)/pow(pow(x0,2)-1,5)-11520*pow(x0,8)/pow(pow(x0,2)-1,4)+5376*pow(x0,6)/pow(pow(x0,2)-1,3)-1120*pow(x0,4)/pow(pow(x0,2)-1,2)+84*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,7)
            case 14:
                derivs[14]=12454041600*x0*(4096*pow(x0,12)/pow(pow(x0,2)-1,6)-12288*pow(x0,10)/pow(pow(x0,2)-1,5)+14080*pow(x0,8)/pow(pow(x0,2)-1,4)-7680*pow(x0,6)/pow(pow(x0,2)-1,3)+2016*pow(x0,4)/pow(pow(x0,2)-1,2)-224*pow(x0,2)/(pow(x0,2)-1)+7)/pow(pow(x0,2)-1,8)
            case 15:
                derivs[15]=87178291200*(-16384*pow(x0,14)/pow(pow(x0,2)-1,7)+53248*pow(x0,12)/pow(pow(x0,2)-1,6)-67584*pow(x0,10)/pow(pow(x0,2)-1,5)+42240*pow(x0,8)/pow(pow(x0,2)-1,4)-13440*pow(x0,6)/pow(pow(x0,2)-1,3)+2016*pow(x0,4)/pow(pow(x0,2)-1,2)-112*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,8)
            case 16:
                derivs[16]=20922789888000*x0*(2048*pow(x0,14)/pow(pow(x0,2)-1,7)-7168*pow(x0,12)/pow(pow(x0,2)-1,6)+9984*pow(x0,10)/pow(pow(x0,2)-1,5)-7040*pow(x0,8)/pow(pow(x0,2)-1,4)+2640*pow(x0,6)/pow(pow(x0,2)-1,3)-504*pow(x0,4)/pow(pow(x0,2)-1,2)+42*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,9)
            case 17:
                derivs[17]=20922789888000*(-65536*pow(x0,16)/pow(pow(x0,2)-1,8)+245760*pow(x0,14)/pow(pow(x0,2)-1,7)-372736*pow(x0,12)/pow(pow(x0,2)-1,6)+292864*pow(x0,10)/pow(pow(x0,2)-1,5)-126720*pow(x0,8)/pow(pow(x0,2)-1,4)+29568*pow(x0,6)/pow(pow(x0,2)-1,3)-3360*pow(x0,4)/pow(pow(x0,2)-1,2)+144*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,9)
            case 18:
                derivs[18]=711374856192000*x0*(65536*pow(x0,16)/pow(pow(x0,2)-1,8)-262144*pow(x0,14)/pow(pow(x0,2)-1,7)+430080*pow(x0,12)/pow(pow(x0,2)-1,6)-372736*pow(x0,10)/pow(pow(x0,2)-1,5)+183040*pow(x0,8)/pow(pow(x0,2)-1,4)-50688*pow(x0,6)/pow(pow(x0,2)-1,3)+7392*pow(x0,4)/pow(pow(x0,2)-1,2)-480*pow(x0,2)/(pow(x0,2)-1)+9)/pow(pow(x0,2)-1,10)
            case 19:
                derivs[19]=6402373705728000*(-262144*pow(x0,18)/pow(pow(x0,2)-1,9)+1114112*pow(x0,16)/pow(pow(x0,2)-1,8)-1966080*pow(x0,14)/pow(pow(x0,2)-1,7)+1863680*pow(x0,12)/pow(pow(x0,2)-1,6)-1025024*pow(x0,10)/pow(pow(x0,2)-1,5)+329472*pow(x0,8)/pow(pow(x0,2)-1,4)-59136*pow(x0,6)/pow(pow(x0,2)-1,3)+5280*pow(x0,4)/pow(pow(x0,2)-1,2)-180*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,10)
            case 20:
                derivs[20]=486580401635328000*x0*(131072*pow(x0,18)/pow(pow(x0,2)-1,9)-589824*pow(x0,16)/pow(pow(x0,2)-1,8)+1114112*pow(x0,14)/pow(pow(x0,2)-1,7)-1146880*pow(x0,12)/pow(pow(x0,2)-1,6)+698880*pow(x0,10)/pow(pow(x0,2)-1,5)-256256*pow(x0,8)/pow(pow(x0,2)-1,4)+54912*pow(x0,6)/pow(pow(x0,2)-1,3)-6336*pow(x0,4)/pow(pow(x0,2)-1,2)+330*pow(x0,2)/(pow(x0,2)-1)-5)/pow(pow(x0,2)-1,11)
        }
    }
}
// ----------------------------------------------------------------------------------------------------
