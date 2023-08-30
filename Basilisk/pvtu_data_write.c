#include "output_vtu_foreach.h" //library to be used from http://basilisk.fr/sandbox/cselcuk/output_vtu_foreach.h

//for unit decimal time interval, we write volume fraction, pressure field, curvature, streamwise vorticity, velocity field and vorticity field 

void save_pvtu_data (scalar f, scalar p,  scalar kappa, scalar l2, scalar omegay, vector u, vector omega, int t) //for float time interval use "double" format specifier instead of "int"
{
  char name[80], subname[80];
  FILE * fp ;

  t > 0 ? sprintf(name, "profiles_%3.3d_n%3.3d.vtu", t,pid()) : sprintf(name, "profiles_n%3.3d.vtu",pid()); //"%3.3d" can be replaced by "%3.1f" for "double" time
  fp = fopen(name, "w");
  output_vtu_ascii_foreach ((scalar *) {f, p, kappa, l2, omegay}, (vector *) {u, omega}, N, fp, false);
  fclose (fp);

  if (pid()==0){
    t > 0 ? sprintf(name, "profiles_%3.3d.pvtu", t) : sprintf(name, "profiles.pvtu");
    t > 0 ? sprintf(subname, "profiles_%3.3d",  t) : sprintf(subname, "profiles");
    fp = fopen(name, "w");
    output_pvtu_ascii ((scalar *) {f, p, kappa, l2, omegay}, (vector *) {u, omega}, N, fp, subname);
    fclose (fp);
  }
  MPI_Barrier(MPI_COMM_WORLD);
}

event loggfilee (t = 1; t <= MAXTIME; t += 1){
  scalar kappa[], l2[], omegay[];
  vector omega[];
  lambda2(u, l2);

  foreach()
    omegay[] = (u.x[0,0,1] - u.x[0,0,-1] - u.z[1,0,0] + u.z[-1,0,0])/(2.*Delta);

  foreach(){
    omega.x[] = (u.z[0,1,0] - u.z[0,-1,0] - u.y[0,0,1] + u.y[0,0,-1])/(2.*Delta);
    omega.y[] = (u.x[0,0,1] - u.x[0,0,-1] - u.z[1,0,0] + u.z[-1,0,0])/(2.*Delta);
    omega.z[] = (u.y[1,0,0] - u.y[-1,0,0] - u.x[0,1,0] + u.x[0,-1,0])/(2.*Delta);
  }

  boundary((scalar *){omegay, omega});
  curvature(f, kappa);
  save_pvtu_data(f, p, kappa, l2, omegay, u, omega, (int) t);
}
