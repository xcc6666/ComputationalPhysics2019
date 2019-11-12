{
int N=10000;
TRandom r;
double sum=0;
for (int i=0; i<N; i++) {
   sum += sin(r.Rndm());
}
printf("for N=%d, sum= %f\n", N, sum);
printf("Exact= %f\n", 1.0-cos(1.0));
}
