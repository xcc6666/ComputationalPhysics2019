{
TCanvas *c1= new TCanvas("c1", "triangles", 10,10,700,700);
TRandom r;
Double_t dx=0.2; Double_t dy=0.2; 
Int_t ntriangles=60;
Int_t ncolors = gStyle->GetNumberOfColors();
Double_t x[4], y[4];
TColor *c;
Int_t ci;
for (Int_t i=0; i<ntriangles; i++) {
 x[0]=r.Uniform(.05,.95); y[0]=r.Uniform(.05,.95);
 x[1]=x[0]+dx*r.Rndm(); y[1]=y[0]+dy*r.Rndm();
cout<<r.Rndm()<<" "<<r.Rndm()<<endl;
 x[2]=x[1]-dx*r.Rndm(); y[2]=y[1]-dy*r.Rndm();
 x[3]=x[0]; y[3]=y[0];
 TPolyLine *pl = new TPolyLine(4,x,y);
 ci = ncolors*r.Rndm();
 pl->SetFillColor(ci);
 pl->Draw("f"); 
}
}
