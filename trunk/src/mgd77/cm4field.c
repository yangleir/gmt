#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define	FALSE	0
#define	TRUE	1

#ifndef MIN
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif
#define I_DIM(x, y) (((x) > (y)) ? (x) - (y) : 0)

#ifndef M_PI
#define M_PI	3.14159265358979323846
#endif
#define D2R   M_PI/180.
#define R2D   180./M_PI

int cm4field_(char **path, int *load, int *indx, int cord, int *pred, int curr, int coef,
	int *nhmf, int *nlmf, double *ut, int n_times, double *theta, double *phi, double *alt, 
	double *dst, double *f107, double *bmdl, double *jmdl, double *gmdl, int cerr, int *no, int *nf, 
	int n_pts, int nval, int nfval, double *out_field);
void ymdtomjd(int yearad, int month, int dayofmonth, int *mjd, int *dayofyear);
void ydtomjdx(int yearad, int dayofyear, int * mjd, int *month, int *dayofmonth, int *daysinmonth);
double intdst(int mjdl, int mjdh, int mjdy, int msec, double *dstx, int *cerr);
double intf107(int iyrl, int imol, int iyrh, int imoh, int iyr, int imon, int idom, int *idim, 
	int msec, double *f107x, int *cerr);
double getmut2(double thenmp, double phinmp, int iyear, int iday, int msec);
void sun2(int iyr, int iday, double secs, double *gst, double *slong, double *srasn, double *sdec);
void rmerge_(double *rmrg, double *rmlt);
void tsearad(int full, int ks, int kr, int ns, int ng, double f, double *t, double *e, double *g);
void tseardr(int full, int ks, int kr, int ns, int ng, double f, double *t, double *e, double *g);
void mseason(int ks, int ns, int ng, double d, double *t, double *e, double *g);
void iseason(int ks, int ns, int ng, double f, double *t, double *e, double *g);
void mpotent(int nmax, int mmax, int nd, int nz, double cphi, double sphi, double *d, double *z);
void jtbelow(int pmin, int pmax, int nmax, int mmax, double r, double rref, int nz, double *z);
void jtabove(int pmin, int pmax, int nmax, int mmax, double r, double rref, int nz, double *z);
void jtbcont(int pmin, int pmax, int nmax, int mmax, double rold, double rnew, int nz, double *z);
void mstream(int nmax, int mmax, int nd, int nz, double cphi, double sphi, double faor, double *d, double *z);
void jpoloid(int pmin, int pmax, int nmax, int mmax, double r, double rm, int nd, int nz, double *t, double *d, double *z);
void blsgen(int nc, int nd, int ni, double *b, double *c, double *dldc);
void getgmf(int nder, int ns, double *ep, double *tm, double *b, double *c, double *g, int *h, int *o, double *p);
void dbspln_(int *l, double *t, int *n, int * d__, int *k, double *x, double *b, double *w);
void getgxf(int pmin, int pmax, int nmax, int mmax, int *ng, double *e, double *g, double *t);
void bfield(int rgen, int nmxi, int nmxe, int nmni, int nmne, int mmxi, int mmxe, int mmni,
	int mmne, int grad, int ctyp, int dtyp, int ityp, int etyp, double ep, double re, 
	double rp, double rm, double tm, double clat, double elon, double h, double dst, double dstt, 
	double *rse, int *nc, int *na, double *ro, double *theta, int *atyp, int *dsti, int *bori, int *bkni, 
	double *bkpi, int *tdgi, int *dste, int *bore, int *bkne, double *bkpe, int *tdge, double *a, 
	double *b, double *c, double *p, double *r, double *t, int *u, double *w, double *dsdc, 
	double *dldc, double *dlda, int *cerr);
void prebf_(int *rgen, int *ityp, int *etyp, int *dtyp, int *grad, int *nmni, int *nmxi, int *
	nmne, int *nmxe, int *mmni, int *mmxi, int *mmne, int *mmxe, int *nmax, int *mmin, int *mmax, int *
	ns, int *nsi, int *nse, int *nc, int *nci, int *nce, int *na, int *np, int *ii, int *ie, int *
	atyp, int *dsti, int *bori, int *bkni, int *tdgi, int *dste, int *bore, int *bkne, int *tdge, int *u, int *cerr);
void fdlds_(int *rgen, int *grad, int *ctyp, double *clat, double *phi, double *h, double *re, 
	double *rp, double *rm, double *ro, int *nsi, int *nc, int *nci, int *np, int *ii, int *ie, int *
	nmni, int *nmxi, int *nmne, int *nmxe, int *nmax, int *mmni, int *mmxi, int *mmne, int *mmxe, int *
	mmin, int *mmax, double *theta, double *p, double *r, double *t, int *u, double *w, double *dldc, int *cerr);
void geocen_(int *ctyp, double *re, double *rp, double *rm, double *h, double *clat, double *r, double *theta, double *sinthe, double *costhe);
void schmit_(int *grad, int *rgen, int *nmax, int *mmin, int *mmax, double *sinthe, double *costhe, double *p, double *r);
void srecur_(int *grad, int *nmax, int *mmin, int *mmax, int *ksm2, int *ktm2, int *npall, int *
	nad1, int *nad2, int *nad3, int *nad4, int *nad5, int *nad6, int *nad7, int *nad8, double *r);
void trigmp(int mmax, double phi, double *t);
void tdc(int grad, int nc, double clat, double theta, double *dldc, double *r);
void fdsdc_(int *rgen, int *ityp, int *etyp, int *nsi, int *nse, int *nc, int *nci, double *ta,
	double *tb, double *dst, double *dstt, int *dsti, int *bori, int *bkni, double *bkpi, int *tdgi, 
	int *dste, int *bore, int *bkne, double *bkpe, int *tdge, int *u, double *w, double *dsdc, int *cerr);
void taylor(int nc, int ns, double ta, double tb, int *tdeg, int *u, double *dsdt, double *dsdc);
void bsplyn(int nc, int ns, double *ta, double *tb, int *bord, int *bkno, double *bkpo, int *u, double *dtdb, double *dsdc, int cerr);
void sbspln_(double *ta, double *tb, int *n, int *k, double *bkpo, double *dtdb, double *dsdc, int *cerr);
void tbspln_(double *t, int *n, int *k, double *bkpo, double *dtdb, int *cerr);
void dstorm(int nc, int ns, double *dst, double *dstt, int *dstm, int *u, double *dsdc);
void fdldc(int grad, int nc, double *dsdc, double *dldc);
void blgen(int grad, int nc, double *b, double *c, double *dldc);
void bngen_(double *b);
void tec(int grad, int k, int nc, double *theta, double *phi, double *b, double *dldc, double *r);
void tse(int grad, int k, int nc, double *rse, double *b, double *dldc, double *r);
void tms(int grad, int k, int nc, int na, int ia, double *a, double *b, double *dldc, double *dlda, double *r);
void fdldeu_(int *k, int *na, int *ia, double *seulx, double *ceulx, double *seuly, double *ceuly, 
	double *seulz, double *ceulz, double *r, double *b, double *dlda);
void tnm_(int *grad, int *k, int *nc, int *na, int *ia, double *a, double *b, double *dldc, double *dlda, double *r);
void fdldno_(int *k, int *na, int *ia, double *schix, double *cchix, double *schiy, double *cchiy, 
	double *schiz, double *cchiz, double *r, double *b, double *dlda);
void fdldsl_(int *k, int *na, int *ia, double *b, double *dlda);
void tvn_(int *grad, int *k, int *nc, int *na, int *ia, double *a, double *b, double *dldc, double *dlda, double *r);
void tbi_(int *k, int *na, int *ia, double *a, double *b, double *dlda);
void fdldbi_(int *k, int *na, int *ia, double *dlda);
void ltrans(int n, int m, double *q, double *r, double *s);
void ltranv(int rfac, int n, int m, double *r, double *v);
int nshx(int nmax, int nmin, int mmax, int mmin);
int nlpx(int nmax, int mmax, int mmin);
int i8ssum(int abeg, int alen, int *a);
void i8vset(int abeg, int alen, int s, int *a);
void i8vadd(int abeg, int bbeg, int cbeg, int vlen, int *a, int *b, int *c);
void i8vadds(int abeg, int bbeg, int vlen, int s, int *a, int *b);
void i8vcum(int abas, int abeg, int alen, int *a);
void i8vdel(int abas, int abeg, int alen, int *a);
void r8vset(int abeg, int alen, double s, double *a);
double r8sdot(int abeg, int bbeg, int vlen, double *a, double *b);
double r8ssum_(int *abeg, int *alen, double *a);
void r8slt(int abeg, int alen, double s, double *a, int *j);
void r8vsub(int abeg, int bbeg, int cbeg, int vlen, double *a, double *b, double *c);
void r8vmul(int abeg, int bbeg, int cbeg, int vlen, double *a, double *b, double *c);
void r8vscale(int abeg, int alen, double s, double *a);
void r8vscats(int qbeg, int qlen, double s, int *q, double *a);
void r8vlinkt(int abeg, int bbeg, int vlen, double s, double *a, double *b);
void r8vlinkq(int abeg, int bbeg, int cbeg, int vlen, double s, double *a, double *b, double *c);
void r8vgathp(int abeg, int ainc, int bbeg, int blen, double *a, double *b);
double d_mod(double x, double y);
double pow_di(double *ap, int *bp);
int i_dnnt(double x);

/* --------------------------------------------------------------------------- */
int main(int argc, char **argv) {

	int	i, j, ijour, imon, ian, multiple_date = 0, multiple_alt = 0, n_pts, pos_slash = 0;
	int	nval = 0, nfval = 0, no[7], nf[7] = {0,1,2,3,4,5,6}, n_arg_no_char = 0;

	int	date_mmddyyyy = 0, date_year = 1, date_year_jul = 0;
	int	DstF107_index[2] = {TRUE, TRUE};
	int	CM4_load[3] = {TRUE, TRUE, TRUE}; 
	int	pred[6] = {TRUE, TRUE, TRUE, TRUE, FALSE, FALSE};
	int	nlmf[2] = {1,  14};
	int	nhmf[2] = {13, 65};
	int	geodetic = FALSE;
	int	curr = FALSE;
	int	coef = FALSE;		/* no coefficients generated */
	int	cerr = 0;		/* error flag */
	int	n_times;		/* Number of time elements */
	int	got_point = FALSE;
	char	*path[3];
	double	*Dst, F107;
	double	gmdl[1];
	double	bmdl[21];
	double	jmdl[12];
	double	lon[2], lat[2], alt[1], year[2], *out;

	path[0] = path[1] = path[2] = NULL;

	path[0] = "C:\\a1\\gmt\\CM4\\umdl.CM4";
	path[1] = "C:\\a1\\gmt\\CM4\\Dst_all.wdc";
	path[2] = "C:\\a1\\gmt\\CM4\\F107_mon.plt";

	if (FALSE) {
		fprintf (stderr, "usage: cm4field [-F<thxyzdi[/1234567]>] -Plon/lat/alt/date -S[cMin/Max][lMin/Max] \n");
		fprintf (stderr, "\tlon and lat are column or row vectors with the positions where to compute the IGRF\n");
		fprintf (stderr, "\talt is the altitude in km positive up (it can be a scalar or a vector with the same size as lon)\n");
		fprintf (stderr, "\tyear is the date of the aquisition data. Accepted date formats are:\n");
		fprintf (stderr, "\t  decimal year. e.g 2004.5\n");
		fprintf (stderr, "\t  NOTE: in case of decimal years, a vector of dates is also permited.\n");
		fprintf (stderr, "\t  a vector with [year julian]. e.g. [2004 56]\n");
		fprintf (stderr, "\t  a vector with [day month year]. e.g. [20 04 2004]\n");
		fprintf (stderr, "\t-D<Dst_filename> full name of the 'Dst_all.wdc' file.\n");
		fprintf (stderr, "\t-f<F107_filename> full name of the 'F107_mon.plt' file.\n");
		fprintf (stderr, "\t-F Dataflags is a string made up of 1 or more of these characters:\n");
		fprintf (stderr, "\t	t means list total field\n");
		fprintf (stderr, "\t	h means list horizontal field\n");
		fprintf (stderr, "\t	x means list X component\n");
		fprintf (stderr, "\t	y means list Y component\n");
		fprintf (stderr, "\t	z means list Z component\n");
		fprintf (stderr, "\t	d means list declination\n");
		fprintf (stderr, "\t	i means list inclination\n");
		fprintf (stderr, "\t  Append a number to indicate the requested field contribution(s)\n");
		fprintf (stderr, "\t	1 means Main field 1\n");
		fprintf (stderr, "\t	2 means Main field 2\n");
		fprintf (stderr, "\t	3 Primary Magnetospheric field\n");
		fprintf (stderr, "\t	4 Induced Magnetospheric field\n");
		fprintf (stderr, "\t	5 Primary ionospheric field\n");
		fprintf (stderr, "\t	6 Induced ionospheric field\n");
		fprintf (stderr, "\t	7 Toroidal field\n");
		fprintf (stderr, "\t  Use several numbers to add up the different contributions. For example\n");
		fprintf (stderr, "\t  -Ft/12 computes the total field due to Core and Lithospheric sources.\n");
		fprintf (stderr, "\t	The data is written out in the order specified in <dataflags>\n");
		fprintf (stderr, "\t	[Default is -Fthxyzdi/1]\n");
		fprintf (stderr, "\t-Plon/lat/alt/date full name of the 'Dst_all.wdc' file.\n");
		return;
	}

	Dst = (double *) calloc((size_t)(1), sizeof(double));	/* We need at least a size of one in case a value is given in input */

	for (i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
				case 'D':
					if ((argv[i][2] > 47) && (argv[i][2] < 58)) {	/* arg is numeric -> Dst Index */
						Dst[0] = atof(&argv[i][2]);
						DstF107_index[0] = FALSE;
					}
					else {
						path[1] = &argv[i][2];
						if (!CM4_load[1]) CM4_load[1] = TRUE;
					}
					break;
				case 'f':
					if ((argv[i][2] > 47) && (argv[i][2] < 58)) {	/* arg is numeric -> Dst Index */
						F107 = atof(&argv[i][2]);
						DstF107_index[1] = FALSE;
					}
					else {
						path[2] = &argv[i][2];
						if (!CM4_load[2]) CM4_load[2] = TRUE;
					}
					break;
				case 'F':
					for (j = 2; argv[i][j]; j++) {
						if (argv[i][j] == '/') {
							pos_slash = j;
							break;
						}
						switch (argv[i][j]) {
							case 't':		/* Total field is requested */
								no[nval++] = 0;
								break;
							case 'h':		/* Horizontal field is requested */
								no[nval++] = 1;
								break;
							case 'x':		/* X component is requested */
								no[nval++] = 2;
								break;
							case 'y':		/* Y component is requested */
								no[nval++] = 3;
								break;
							case 'z':		/* Z component is requested */
								no[nval++] = 4;
								break;
							case 'd':		/* Declination is requested */
								no[nval++] = 5;
								break;
							case 'i':		/* Innclination is requested */
								no[nval++] = 6;
								break;
						}
					}
					if (pos_slash) {
						for (j = pos_slash; argv[i][j]; j++) {
							switch (argv[i][j]) {
								case '1':		/* Main field 1 */
									nf[nfval++] = 0;
									break;
								case '2':		/* Main field 2 */
									nf[nfval++] = 1;
									break;
								case '3':		/* Primary Magnetospheric field */
									nf[nfval++] = 2;
									break;
								case '4':		/* Induced Magnetospheric field */
									nf[nfval++] = 3;
									break;
								case '5':		/* Primary ionospheric field */
									nf[nfval++] = 4;
									break;
								case '6':		/* Induced ionospheric field */
									nf[nfval++] = 5;
									break;
								case '7':		/* Toroidal field */
									nf[nfval++] = 6;
									break;
							}
						}
					}
					break;
				case 'G':
					geodetic = TRUE;
					break;
				case 'M':
					path[0] = &argv[i][2];
					break;
				case 'P':
					j = sscanf (&argv[i][2], "%lf/%lf/%lf/%lf", &lon[0], &lat[0], &alt[0], &year[0]);
					n_pts = n_times = 1;
					got_point = TRUE;
					break;
				case 'S':
					if (argv[i][2] == 'c') {
						j = sscanf (&argv[i][3], "%d/%d", &nlmf[0], &nhmf[0]);
						if (j != 2) 
							fprintf (stderr, "CM4 -S option ERROR, usage: -Sc<low/high>\n");
					}
					if (argv[i][2] == 'l') {
						j = sscanf (&argv[i][3], "%d/%d", &nlmf[1], &nhmf[1]);
						if (j != 2) 
							fprintf (stderr, "CM4 -S option ERROR, usage: -Sl<low/high>\n");
					}
					break;
			}
		}
	}

	/* --------- CODE TO INPUT DATA FROM FILE GOES HERE ---------------- */
	if (!got_point) {
		lon[0] = -10;
		lat[0] = 45;
		lon[1] = -10;
		lat[1] = 45;
		n_pts = 2;		/* Number of data points */
		alt[0] = 0;		/* Currently altitude must be constant */
		year[0] = 2000;
		year[1] = 2000.3;
		n_times = 2;		/* Number of time values. Time may be constant and than n_times = 1 */
	}
	/* ------------------------------------------------------------------ */

	/* Sort the order in which the parameters appear */
	if (nval == 0) {		/* Nothing selected, default used */
		nval = 7;
		for (i = 0; i < 7; i++) no[i] = i;
	}
	if (nval > 7) nval = 7;		/* Can happen with a missuse of -F */
	if (nfval == 0) 		/* Nothing selected, retain only the main field */
		nfval = 1;

	out = (double *) calloc((size_t)(n_pts * nval), sizeof(double));	/* To hold the complete output (field only) */

	cm4field_(path, CM4_load, DstF107_index, geodetic, pred, curr, coef, nhmf, nlmf, year, 
		n_times, lat, lon, alt, Dst, &F107, bmdl, jmdl, gmdl, cerr, no, nf, n_pts, nval, nfval, out);

	/* One should not need to transmit back the bmdl variable since output data is in 'out' array but it
	   makes it easy to test against the original fortran version */
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[0], bmdl[1], bmdl[2]);
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[3],bmdl[4],bmdl[5]);
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[6],bmdl[7],bmdl[8]);
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[9],bmdl[10],bmdl[11]);
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[12],bmdl[13],bmdl[14]);
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[15],bmdl[16],bmdl[17]);
	fprintf(stderr, "%8.2f\t%8.2f\t%8.2f\n", bmdl[18],bmdl[19],bmdl[20]);

	/* Temporary - for testing only */
	if (n_pts > 0) {
		for (i = 0; i < n_pts; i++) {
			for (j = 0; j < nval; j++)
				fprintf(stderr, "%.2f\t", out[i*nval+j]);
			fprintf(stderr,"\n");
		}
	}
}


int cm4field_(char **path, int *load, int *indx, int cord, int *pred, int curr,
	int coef, int *nhmf, int *nlmf, double *ut, int n_times, double *theta, double *phi, double *alt, 
	double *dst, double *f107, double *bmdl, double *jmdl, double *gmdl, int cerr, int *no, int *nf, 
	int n_pts, int nval, int nfval, double *out_field) {

	int c__1356 = 1356, c__13680 = 13680;
	int i, j, k, l, n, p, nu, mz, nz, mu, js, jy, nt, mt, iyr, jyr, jf107;
	int lum1, lum2, lum3, lum4, lum5, lum6, lum7, nsm1, nsm2, lcmf, idim[12], omdl;
	int lsmf, lpos, lcmg, lsmg, lcsq, lssq, lcto, lsto, lrto, idoy, n_Dst_rows;
	int *msec, *mjdy, imon, idom, jaft, jmon, jdom, jmjd, jdoy, mjdl, mjdh, iyrl, imol, iyrh, imoh;
	int nout, nygo, igen, nmax, nmin, nobo, nopo, nomn, nomx, noff, noga, nohq, nimf, nyto, nsto, ntay, mmdl;
	int us[4355], bord[4355], bkno[4355], pbto, peto, csys, jdst[24];
	double *mut, *dstx, dstt = 0., x, y, z, h, t, dumb;
	double bc[28], re, hq[53040], wb[58], ht[17680], xd, yd, rm, xg, ro, rp, yg, zg, zd;
	double ru, rt, rse[9], doy, fyr, ws[4355], gamf[8840], cego, epch, bkpo[12415];
	double trig[132], epmg[1356], esmg[1356];
	double f107x[1200];	/* was [100][12] */
	double hymg[8136];	/* was [1356][6] */
	double *gcto_or = NULL;	/* was [13680][5][2] */ 
	double *gcto_mg = NULL;	/* was [2736][3][2][2] */ 
	double *gpsq;		/* was [13680][5][2] */
	double *gssq;		/* was [13680][5] */
	double *gpmg;		/* was [1356][5][2] */ 
	double *gsmg;		/* was [1356][5][2] */  
	static double hysq[82080];	/* was [13680][6] */ 
	static double epsq[13680], essq[13680], ecto[16416], hyto[49248], pleg[4422], rcur[9104];
	double rlgm[15], rrgt[9], tsmg[6], tssq[6], tsto[6], tdmg[12], tdsq[10], tdto[10];
	double rtay_dw, rtay_or, sinp, fsrf, rtay, frto, frho, thetas, rtay_dk;
	double cnmp, enmp, omgs, omgd, hion, cpol, epol, ctmp, stmp, cemp, semp, rion, fdoy, clat, elon;
	double sthe, cthe, psiz, cpsi, spsi, ctgo, stgo, sego, cdip, edip, ctmo, stmo, cemo, semo, taus, taud, cosp;
	char line[BUFSIZ];

	FILE *fp;

/* ======================================================================= */
/* Main Field potential expansion parameters */
/* ======================================================================= */
/* Magnetospheric and coupled Induction potential expansion parameters */
/* ======================================================================= */
/* Sq and coupled Induction potential expansion parameters */
/* ======================================================================= */
/* Toroidal scalar or stream function expansion parameters */
/* ======================================================================= */
/* Set maximum number of years for index table limits */
/* ======================================================================= */

	if (load[0]) {
		if ((fp = fopen(path[0], "r")) == NULL) {
			fprintf (stderr, "CM4: Could not open file %s\n", path[0]);
			return 1;
		}

		fgets(line, BUFSIZ, fp);
		sscanf (line, "%d %d %d", &lsmf, &lpos, &lcmf);
		fgets(line, BUFSIZ, fp);
		sscanf (line, "%d", &lum1);
		fgets(line, BUFSIZ, fp);
		sscanf (line, "%lf %lf %lf %lf", &epch, &re, &rp, &rm);
		for (j = 0; j < lsmf; ++j)
			fscanf (fp, "%d", &bord[j]);
		for (j = 0; j < lsmf; ++j)
			fscanf (fp, "%d", &bkno[j]);
		for (j = 0; j < lpos; ++j)
			fscanf (fp, "%lf", &bkpo[j]);
		for (j = 0; j < lcmf; ++j)
			fscanf (fp, "%lf", &gamf[j]);

		fscanf (fp, "%d %d", &lcmg, &lsmg);
		fscanf (fp, "%d %d %d %d %d %d", &lum1, &lum2, &lum3, &lum4, &lum5, &lum6);
		fscanf (fp, "%lf %lf %lf %lf %lf %lf %lf", &cnmp, &enmp, &omgs, &omgd, &re, &rp, &rm);
		gpmg = (double *) calloc((size_t)(2 * lsmg * lcmg), sizeof(double));
		for (k = 0; k < 2; ++k)
			for (j = 0; j < lsmg; ++j)
				for (i = 0; i < lcmg; ++i)
					fscanf (fp, "%lf", &gpmg[i + (j + k * 5) * 1356]);

		gsmg = (double *) calloc((size_t)(2 * lsmg * lcmg), sizeof(double));
		for (k = 0; k < 2; ++k)
			for (j = 0; j < lsmg; ++j)
				for (i = 0; i < lcmg; ++i)
					fscanf (fp, "%lf", &gsmg[i + (j + k * 5) * 1356]);

		fscanf (fp, "%d %d", &lcsq, &lssq);
		fscanf (fp, "%d %d %d %d %d %d", &lum1, &lum2, &lum3, &lum4, &lum5, &lum6);
		fscanf (fp, "%lf %lf %lf %lf %lf %lf %lf %lf", &cnmp, &enmp, &omgs, &omgd, &re, &rp, &rm, &hion);
		gpsq = (double *) calloc((size_t)(2 * lssq * lcsq), sizeof(double));
		for (k = 0; k < 2; ++k)
			for (j = 0; j < lssq; ++j)
				for (i = 0; i < lcsq; ++i)
					fscanf (fp, "%lf", &gpsq[i + (j + k * 5) * 13680]);

		gssq = (double *) calloc((size_t)(lssq * lcsq), sizeof(double));
		for (j = 0; j < lssq; ++j)
			for (i = 0; i < lcsq; ++i)
				fscanf (fp, "%lf", &gssq[i + j * 13680]);

		fscanf (fp, "%d %d %d", &lcto, &lsto, &lrto);
		fscanf (fp, "%d %d %d %d %d %d %d", &lum1, &lum2, &lum3, &lum4, &lum5, &lum6, &lum7);
		fscanf (fp, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", &cnmp, &enmp, &omgs, &omgd, &re, &rp, &rm, &rtay_dw, &rtay_dk);
		if (pred[3]) { 		/* In other cases the next coefficients are not used, so no waist time/memory with them */
			gcto_mg = (double *) calloc((size_t)(2 * lrto * lsto * lcto), sizeof(double));
			for (l = 0; l < 2; ++l)
				for (k = 0; k < lrto; ++k)
					for (j = 0; j < lsto; ++j)
						for (i = 0; i < lcto; ++i)
							fscanf (fp, "%lf", &gcto_mg[i + (j + (k + (l << 1)) * 3) * 2736]);
		}
		else			/* Jump the unused coeffs */
			for (l = 0; l < 2 * lrto * lsto * lcto; ++l)
				fscanf (fp, "%lf", &dumb);

		fscanf (fp, "%d %d %d", &lcto, &lsto, &lrto);
		fscanf (fp, "%d %d %d %d %d %d %d", &lum1, &lum2, &lum3, &lum4, &lum5, &lum6, &lum7);
		fscanf (fp, "%lf %lf %lf %lf %lf %lf %lf %lf", &cnmp, &enmp, &omgs, &omgd, &re, &rp, &rm, &rtay_or);
		if (pred[3] && !pred[4]) { 	/* In other cases the next coefficients are not used, so no waist time/memory with them */
			gcto_or = (double *) calloc((size_t)(lrto * lsto * lcto), sizeof(double));
			for (k = 0; k < lrto; ++k)
				for (j = 0; j < lsto; ++j)
					for (i = 0; i < lcto; ++i)
						fscanf (fp, "%lf", &gcto_or[i + (j + k * 5) * 13680]);
		}

		fclose(fp);
		cpol = cnmp * D2R;
		epol = enmp * D2R;
		ctmp = cos(cpol);
		stmp = sin(cpol);
		cemp = cos(epol);
		semp = sin(epol);
		rion = rm + hion;
	}

	mut = (double *) calloc((size_t)(n_times), sizeof(double));
	msec = (int *) calloc((size_t)(n_times), sizeof(int));
	mjdy = (int *) calloc((size_t)(n_times), sizeof(int));
	for (n = 0; n < n_times; ++n) {		/* If time is not constant compute the mut array */
		iyr = (int) (ut[n]);
		fyr = ut[n] - (double) iyr;
		doy = fyr * (double) (366 - MIN(1, iyr % 4));
		idoy = (int) doy;
		fdoy = doy - (double) idoy;
		++idoy;
		msec[n] = i_dnnt(fdoy * 8.64e7);
		ydtomjdx(iyr, idoy, &mjdy[n], &imon, &idom, idim);
		mut[n] = getmut2(cnmp, enmp, iyr, idoy, msec[n]);
	}

	csys = 1;
	if (cord) csys = 0;
	if (indx[0]) {
		if (load[1]) {
			int k;
			if ((fp = fopen(path[1], "r")) == NULL) {
				fprintf (stderr, "CM4: Could not open file %s\n", path[1]);
				return 1;
			}
			jaft = 0;
			n = 0;
			n_Dst_rows = 16709;	/* Current (28-04-2009) number of lines in Dst_all.wdc file */
			dstx = (double *) calloc((size_t)(n_Dst_rows * 24), sizeof(double));
			/* One improvment would be to compute year_min/year_max and retain only the needed data in dstx */

			while (fgets (line, BUFSIZ, fp)) {
				sscanf (&line[3], "%2d %2d", &jyr, &jmon);
				sscanf (&line[8], "%2d", &jdom);
				for (i = 0; i < 24; ++i)
					sscanf (&line[20+i*4],"%4d", &jdst[i]);
				jyr += 1900;
				if (jyr < 1957) jyr += 100;
				ymdtomjd(jyr, jmon, jdom, &jmjd, &jdoy);
				if (jaft == 0) {
					jaft = 1;
					mjdl = jmjd;
				}
				if (n > n_Dst_rows) {
					n_Dst_rows += 1000;
					dstx = (double *) realloc(dstx, (size_t)(n_Dst_rows * 24) * sizeof(double));
				}
				k = (jmjd - mjdl) * 24;
				for (j = 0; j < 24; ++j)
					dstx[k + j] = (double) jdst[j];
				n++;
			}
			fclose(fp);
			mjdh = jmjd;
    		}
		if (n_times > 1)	/* Need to re-allocate memory for all n_times in dst array */
			dst = (double *) realloc(dst, (size_t)(n_times) * sizeof(double));

		for (n = 0; n < n_times; ++n)
			dst[n] = intdst(mjdl, mjdh, mjdy[n], msec[n], dstx, &cerr);

		free((void *) dstx);
		if (cerr > 49) return 1;
	}
	if (indx[1]) {
		if (load[2]) {
			if ((fp = fopen(path[2], "r")) == NULL) {
				fprintf (stderr, "CM4: Could not open file %s\n", path[2]);
				return 1;
			}
			jaft = 0;
			while (fgets (line, BUFSIZ, fp)) {
				if (line[9] != '-') {
					sscanf (line, "%d %d %d", &jyr, &jmon, &jf107);
					if (jaft == 0) {
						jaft = 1;
						iyrl = jyr;
						imol = jmon;
					}
					f107x[(jyr - iyrl) * 12 + jmon-1] = (double)jf107 / 10.;
				}
			}
			fclose(fp);
			iyrh = jyr;
			imoh = jmon;
		}
		/* MUST INVESTIGATE IF IT WORTH HAVING AN ARRAY OF f107 LIKE IN THE DST CASE */
		*f107 = intf107(iyrl, imol, iyrh, imoh, iyr, imon, idom, idim, msec[0], f107x, &cerr);
		if (cerr > 49) return 1;
	}
	free ((void *) msec);
	free ((void *) mjdy);

	/* LOOP over number of input points (many computations below are useless repeated - room for improvment */
	for (n = 0; n < n_pts; ++n) {
		r8vset(1, 21, 0., &bmdl[0]);
		if (curr) r8vset(1, 12, 0., &jmdl[0]);
		clat = (90 - theta[n]) * D2R;
		elon = phi[n] * D2R;

		if (coef) {
			nout = 1;	nygo = 0;
			if (pred[1]) nygo = MAX(nygo,113);
			if (pred[2]) nygo = MAX(nygo,1368);
			if (pred[3]) nygo = MAX(nygo,1368);
		}
		if (pred[0]) {
			igen = 1;
			nmax = MAX(nhmf[0],nhmf[1]);
			nmin = MIN(nlmf[0],nlmf[1]);
			nobo = nshx(nmin - 1, 1, nmin - 1, 0);
			nopo = i8ssum(1, nobo, bkno) + (nobo << 1);
			bfield(igen, nmax, 0, nmin, 1, nmax, 0, 0, 0, 0, csys, 3, 2, 0, 
				epch, re, rp, rm, ut[n], clat, elon, alt[0], dst[n], dstt, rse, &nz, 
				&mz, &ro, &thetas, us, us, &bord[nobo], &bkno[nobo], &bkpo[nopo], us, us, us, us, 
				ws, us, gamf, bc, gamf, pleg, rcur, trig, us, ws, ht, hq, hq, &cerr);
			if (cerr > 49) return 1;
			nomn = nshx(nlmf[0] - 1, 1, nlmf[0] - 1, 0);
			nomx = nshx(nhmf[0], 1, nhmf[0], 0);
			noff = nomn - nobo;
			nsm1 = I_DIM(nomx, nomn);
			noga = i8ssum(1, nomn, bord) + i8ssum(1, nomn, bkno) + nomn;
			nohq = i8ssum(nobo + 1, noff, bord) + i8ssum(nobo + 1, noff, bkno) + noff;
			nimf = i8ssum(nobo + 1, nsm1, bord) + i8ssum(nobo + 1, nsm1, bkno) + nsm1;
			blsgen(nimf, nz, 3, &bmdl[0], &gamf[noga], &hq[nohq]);
			if (coef) {
				nopo = i8ssum(1, nomn, bkno) + (nomn << 1);
				getgmf(4, nsm1, &epch, &ut[n], wb, &gamf[noga], &gmdl[nout-1], &bkno[nomn], &bord[nomn], &bkpo[nopo]);
				if (cerr > 49) return 1;
			}
			nomn = nshx(nlmf[1] - 1, 1, nlmf[1] - 1, 0);
			nomx = nshx(nhmf[1], 1, nhmf[1], 0);
			noff = nomn - nobo;
			nsm2 = I_DIM(nomx, nomn);
			noga = i8ssum(1, nomn, bord) + i8ssum(1, nomn, bkno) + nomn;
			nohq = i8ssum(nobo + 1, noff, bord) + i8ssum(nobo + 1, noff, bkno) + noff;
			nimf = i8ssum(nomn + 1, nsm2, bord) + i8ssum(nomn + 1, nsm2, bkno) + nsm2;
			blsgen(nimf, nz, 3, &bmdl[3], &gamf[noga], &hq[nohq]);
			if (coef) {
				nygo = MAX(nygo,nsm1 * 5);
				nygo = MAX(nygo,nsm2 * 5);
				nout += nygo * MIN(1,nsm1);
				nopo = i8ssum(1, nomn, bkno) + (nomn << 1);
				getgmf(4, nsm2, &epch, &ut[n], wb, &gamf[noga], &gmdl[nout-1], &bkno[nomn], &bord[nomn], &bkpo[nopo]);
				if (cerr > 49) return 1;
				nout += nygo * MIN(1,nsm2);
			}
		}
		if (pred[1] || pred[2] || pred[3]) {
			if (!pred[0])
				geocen_(&csys, &re, &rp, &rm, alt, &clat, &ro, &thetas, &sthe, &cthe);

			psiz = thetas - clat;
			cpsi = cos(psiz);
			spsi = sin(psiz);
			rlgm[0] = -cpsi;	rlgm[3] = 0.;	rlgm[6] = spsi;
			rlgm[1] = 0.;		rlgm[4] = 1.;	rlgm[7] = 0.;
			rlgm[2] = -spsi;	rlgm[5] = 0.;	rlgm[8] = -cpsi;
			ctgo = cos(thetas);	stgo = sin(thetas);
			cego = cos(elon);	sego = sin(elon);
			rrgt[0] = ctgo * cego;	rrgt[3] = -sego;	rrgt[6] = stgo * cego;
			rrgt[1] = ctgo * sego;	rrgt[4] = cego;		rrgt[7] = stgo * sego;
			rrgt[2] = -stgo;	rrgt[5] = 0.;		rrgt[8] = ctgo;
			rmerge_(rlgm, rrgt);
			rrgt[0] = cemp * ctmp;	rrgt[3] = semp * ctmp;	rrgt[6] = -stmp;
			rrgt[1] = -semp;	rrgt[4] = cemp;		rrgt[7] = 0.;
			rrgt[2] = cemp * stmp;	rrgt[5] = semp * stmp;	rrgt[8] = ctmp;
			rmerge_(rlgm, rrgt);
			xg = stgo * cego;
			yg = stgo * sego;
			zg = ctgo;
			xd = rrgt[0] * xg + rrgt[3] * yg + rrgt[6] * zg;
			yd = rrgt[1] * xg + rrgt[4] * yg + rrgt[7] * zg;
			zd = rrgt[2] * xg + rrgt[5] * yg + rrgt[8] * zg;
			cdip = acos(zd);
			edip = atan2(yd, xd);
			ctmo = zd;
			stmo = sin(cdip);
			cemo = cos(edip);
			semo = sin(edip);
			rrgt[0] = -cemo * ctmo;	rrgt[3] = -semo * ctmo;	rrgt[6] = stmo;
			rrgt[1] = -semo;	rrgt[4] = cemo;		rrgt[7] = 0.;
			rrgt[2] = -cemo * stmo; rrgt[5] = -semo * stmo; rrgt[8] = -ctmo;
			rmerge_(rlgm, rrgt);
			taus = omgs * ut[n];
			taud = omgd * mut[n];
		}
		if (pred[1]) {
			igen = 1;
			bfield(igen, 11, 11, 1, 1, 6, 6, 0, 0, 0, 1, 3, 0, 0,
				epch, re, rp, rm, ut[n], cdip, edip, alt[0], dst[n], dstt, rse, &nu, &mu, 
				&ru, &thetas, us, us, us, us, ws, us, us, us, us, ws, us, gsmg, bc, gsmg, pleg, rcur, 
				trig, us, ws, ht, hq, hq, &cerr);
			if (cerr > 49) return 1;
			js = nu / 2;
			jy = 1;
			trigmp(2, taus, tsmg);
			trigmp(5, taud, tdmg);
			for (p = 0; p <= 5; ++p) {
				cosp = tdmg[p];
				sinp = tdmg[p + 6];
				mpotent(11, 6, nu, c__1356, cosp, sinp, hq, & hymg[jy - 1]);
				mpotent(11, 6, nu, c__1356, cosp, sinp, &hq[js], &hymg[jy + 4067]);
				jy += 226;
			}
			bc[0] = bc[1] = bc[2] = 0.;
			mseason(2, 5, c__1356, dst[n], tsmg, epmg, gpmg);
			blsgen(c__1356, c__1356, 3, bc, epmg, &hymg[4068]);
			ltrans(1, 1, bc, rlgm, &bmdl[6]);
			bc[0] = bc[1] = bc[2] = 0.;
			mseason(2, 5, c__1356, dst[n], tsmg, esmg, gsmg);
			blsgen(c__1356, c__1356, 3, bc, esmg, hymg);
			ltrans(1, 1, bc, rlgm, &bmdl[9]);
			if (curr) {
				bc[0] = bc[1] = bc[2] = 0.;
				jtbelow(0, 5, 11, 6, ro, rm, c__1356, hymg);
				blsgen(c__1356, c__1356, 3, bc, esmg, hymg);
				ltrans(1, 1, bc, rlgm, &jmdl[0]);
			}
			if (coef) {
				getgxf(0, 5, 11, 6, &js, epmg, &gmdl[nout-1], tdmg);
				nout += nygo;
				getgxf(0, 5, 11, 6, &js, esmg, &gmdl[nout-1], tdmg);
				nout += nygo;
			}
		}
		if (pred[2]) {
			igen = 1;
			fsrf = *f107 * .01485 + 1.;
			if (ro < rion) {
				bfield(igen, 60, 60, 1, 1, 12, 12, 0, 0, 0, 1, 3, 0, 0,  
					epch, re, rp, rm, ut[n], cdip, edip, alt[0], dst[n], dstt, rse, &nu,
					&mu, &ru, &thetas, us, us, us, us, ws, us, us, us, us, ws, us, gssq, 
					bc, gssq, pleg, rcur, trig, us, ws, ht, hq, hq, &cerr);
				if (cerr > 49) return 1;
				js = nu / 2;
				jy = 1;
				trigmp(2, taus, tssq);
				trigmp(4, taud, tdsq);
				for (p = 0; p <= 4; ++p) {
					cosp = tdsq[p];
					sinp = tdsq[p + 5];
					mpotent(60, 12, nu, c__13680, cosp, sinp, hq, &hysq[jy - 1]);
					mpotent(60, 12, nu, c__13680, cosp, sinp, &hq[js], &hysq[jy + 41039]);
					jy += 2736;
				}
				bc[0] = bc[1] = bc[2] = 0.;
				iseason(2, 5, c__13680, fsrf, tssq, epsq, gpsq);
				blsgen(c__13680, c__13680, 3, bc, epsq, &hysq[41040]);
				ltrans(1, 1, bc, rlgm, &bmdl[12]);
				bc[0] = bc[1] = bc[2] = 0.;
				iseason(2, 5, c__13680, fsrf, tssq, essq, gssq);
				blsgen(c__13680, c__13680, 3, bc, essq, hysq);
				ltrans(1, 1, bc, rlgm, &bmdl[15]);
				if (curr) {
					bc[0] = bc[1] = bc[2] = 0.;
					jtabove(0, 4, 60, 12, ro, rion, c__13680, &hysq[41040]);
					blsgen(c__13680, c__13680, 3, bc, epsq, &hysq[41040]);
					ltrans(1, 1, bc, rlgm, &jmdl[3]);
					bc[0] = bc[1] = bc[2] = 0.;
					jtbelow(0, 4, 60, 12, ro, rm, c__13680, hysq);
					blsgen(c__13680, c__13680, 3, bc, essq, hysq);
					ltrans(1, 1, bc, rlgm, &jmdl[6]);
				}
				if (coef) {
					getgxf(0, 4, 60, 12, &js, epsq, &gmdl[nout-1], tdsq);
					nout += nygo;
					getgxf(0, 4, 60, 12, &js, essq, &gmdl[nout-1], tdsq);
					nout += nygo;
				}
			}
			else {
				bfield(igen, 60, 0, 1, 1, 12, 0, 0, 0, 0, 1, 3, 0, 0,  
					epch, re, rp, rm, ut[n], cdip, edip, alt[0], dst[n], dstt, 
					rse, &nu, &mu, &ru, &thetas, us, us, us, us, ws, us, us, us, us, ws, us, gssq, 
					bc, gssq, pleg, rcur, trig, us, ws, ht, hq, hq, &cerr);
				if (cerr > 49) return 1;
				jy = 1;
				trigmp(2, taus, tssq);
				trigmp(4, taud, tdsq);
				for (p = 0; p <= 4; ++p) {
					cosp = tdsq[p];
					sinp = tdsq[p + 5];
					mpotent(60, 12, nu, c__13680, cosp, sinp, hq, &hysq[jy - 1]);
					jy += 2736;
				}
				bc[0] = bc[1] = bc[2] = 0.;
				iseason(2, 5, c__13680, fsrf, tssq, epsq, &gpsq[68400]);
				blsgen(c__13680, c__13680, 3, bc, epsq, hysq);
				ltrans(1, 1, bc, rlgm, &bmdl[12]);
				bc[0] = bc[1] = bc[2] = 0.;
				iseason(2, 5, c__13680, fsrf, tssq, essq, gssq);
				blsgen(c__13680, c__13680, 3, bc, essq, hysq);
				ltrans(1, 1, bc, rlgm, &bmdl[15]);
				if (curr) {
					bc[0] = bc[1] = bc[2] = 0.;
					jtbelow(0, 4, 60, 12, ro, rion, c__13680, hysq);
					blsgen(c__13680, c__13680, 3, bc, epsq, hysq);
					ltrans(1, 1, bc, rlgm, &jmdl[3]);
					bc[0] = bc[1] = bc[2] = 0.;
					jtbcont(0, 4, 60, 12, rion, rm, c__13680, hysq);
					blsgen(c__13680, c__13680, 3, bc, essq, hysq);
					ltrans(1, 1, bc, rlgm, &jmdl[6]);
				}
				if (coef) {
					getgxf(0, 4, 60, 12, &nu, epsq, &gmdl[nout-1], tdsq);
					nout += nygo;
					getgxf(0, 4, 60, 12, &nu, essq, &gmdl[nout-1], tdsq);
					nout += nygo;
				}
			}
		}
		if (pred[3]) {
			if (pred[4]) {
				if (pred[5]) {
					pbto = peto = 0;
					nyto = 2736;
					nsto = 3;
					ntay = 1;
					rtay = rtay_dw;
					omdl = FALSE;
					mmdl = 1;
				} else {
					pbto = peto = 0;
					nyto = 2736;
					nsto = 3;
					ntay = 1;
					rtay = rtay_dk;
					omdl = FALSE;
					mmdl = 2;
				}
			} else {
				pbto = 0;
				peto = 4;
				nyto = 13680;
				nsto = 5;
				ntay = 1;
				rtay = rtay_or;
				omdl = TRUE;
				mmdl = 1;
			}
			igen = 1;
			bfield(igen, 60, 0, 1, 1, 12, 0, 0, 0, 0, 1, 3, 0, 0,
				epch, re, rp, rm, ut[n], cdip, edip, 0., dst[n], dstt, rse, &nt, &mt,
				&rt, &thetas, us, us, us, us, ws, us, us, us, us, ws, us, gcto_mg, bc, gcto_mg, 
				pleg, rcur, trig, us, ws, ht, hq, hq, &cerr);
			if (cerr > 49) return 1;
			frto = rm / ro;
			frho = (ro - rtay) / rm;
			jy = 1;
			trigmp(2, taus, tsto);
			trigmp(peto, taud, tdto);
			for (p = pbto; p <= peto; ++p) {
				cosp = tdto[p];
				sinp = tdto[p + 2 + peto - 1];
				mstream(60, 12, nt, nyto, cosp, sinp, frto, hq, &hyto[jy - 1]);
				jy += 2736;
			}
			bc[0] = bc[1] = bc[2] = 0.;
			if (omdl)
				tsearad(omdl, 2, ntay, nsto, nyto, frho, tsto, ecto, gcto_or);
			else
				tsearad(omdl, 2, ntay, nsto, nyto, frho, tsto, ecto, &gcto_mg[(((mmdl << 1) + 1) * 3 + 1) * 2736 - 27360]);

			blsgen(nyto, nyto, 2, bc, ecto, hyto);
			ltrans(1, 1, bc, rlgm, &bmdl[18]);
			if (coef)
				getgxf(pbto, peto, 60, 12, &nt, ecto, &gmdl[nout-1], tdto);

			if (curr) {
	        		bc[0] = bc[1] = bc[2] = 0.;
				jpoloid(pbto, peto, 60, 12, ro, rm, nt, nyto, tdto, hq, hyto);
				blsgen(nyto, nyto, 1, &bc[2], ecto, &hyto[nyto * 2]);
				if (omdl)
					tseardr(omdl, 2, ntay, nsto, nyto, frho, tsto, ecto, gcto_or);
				else
					tseardr(omdl, 2, ntay, nsto, nyto, frho, tsto, ecto, &gcto_mg[(((mmdl << 1) + 1) * 3 + 1) * 2736 - 27360]);

				blsgen(nyto, nyto, 2, bc, ecto, hyto);
				ltrans(1, 1, bc, rlgm, &jmdl[9]);
			}
		}

		x = y = z = 0.0;
		for (k = 0; k < nfval; k++) {			/* Sum all field sources */
			x += bmdl[nf[k]*3]; 
			y += bmdl[nf[k]*3+1]; 
			z += bmdl[nf[k]*3+2]; 
		}
		for (j = 0; j < nval; j++) {			/* Loop over vector field components */
			h = 0.;
			if (no[j] == 0) {
				t = sqrt(x*x + y*y + z*z); 
				out_field[n*nval+j] = t;
			}
			else if (no[j] == 1) {
				h = sqrt(x*x + y*y); 
				out_field[n*nval+j] = h;
			}
			else if (no[j] == 2)
				out_field[n*nval+j] = x; 
			else if (no[j] == 3)
				out_field[n*nval+j] = y; 
			else if (no[j] == 4)
				out_field[n*nval+j] = z; 
			else if (no[j] == 5)
				out_field[n*nval+j] = atan2(y,x) * R2D; 
			else if (no[j] == 6) {
				if (!h) h = sqrt(x*x + y*y);
				out_field[n*nval+j] = atan2(z,h) * R2D; 
			}
		}
	}
	free ((void *) mut);
	free ((void *) gpsq);
	free ((void *) gssq);
	free ((void *) gpmg);
	free ((void *) gsmg);
	if (gcto_or) free((void *) gcto_or);
	if (gcto_mg) free((void *) gcto_mg);
	return 0;
}

void ymdtomjd(int yearad, int month, int dayofmonth, int *mjd, int *dayofyear) {
    static int daysuptomonth[12] = { 0,31,59,90,120,151,181,212,243,273, 304,334 };
    int remyear;

    remyear = yearad - 1900;
    if (remyear > 0) {
	--remyear;
	*mjd = remyear / 4 * 1461 + 15384;
	remyear %= 4;
	*dayofyear = daysuptomonth[month - 1] + dayofmonth;
	if (month > 2) {
	    *dayofyear += I_DIM(remyear, 2);
	}
	*mjd = *mjd + remyear * 365 + *dayofyear;
    } else {
	*dayofyear = daysuptomonth[month - 1] + dayofmonth;
	*mjd = *dayofyear + 15019;
    }
}

void ydtomjdx(int yearad, int dayofyear, int *mjd, int *month, int *dayofmonth, int *daysinmonth) {
    static int daysuptomonth[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    int j, leapday, leapcum, remyear;

    remyear = yearad - 1900;
    if (remyear > 0) {
	--remyear;
	*mjd = remyear / 4 * 1461 + 15384;
	remyear %= 4;
	*mjd = *mjd + remyear * 365 + dayofyear;
	leapday = I_DIM(remyear, 2);
    } else {
	*mjd = dayofyear + 15019;
	leapday = 0;
    }
    for (j = 12; j >= 1; --j) {
	leapcum = MIN(1,I_DIM(j, 2)) * leapday;
	if (daysuptomonth[j - 1] + leapcum < dayofyear) {
	    *month = j;
	    *dayofmonth = dayofyear - daysuptomonth[j - 1] - leapcum;
	    break;
	}
    }

    daysinmonth[0] = 31;
    daysinmonth[1] = leapday + 28;
    daysinmonth[2] = 31;
    daysinmonth[3] = 30;
    daysinmonth[4] = 31;
    daysinmonth[5] = 30;
    daysinmonth[6] = 31;
    daysinmonth[7] = 31;
    daysinmonth[8] = 30;
    daysinmonth[9] = 31;
    daysinmonth[10] = 30;
    daysinmonth[11] = 31;
}

double intdst(int mjdl, int mjdh, int mjdy, int msec, double *dstx, int *cerr) {
    int hbot, mjdt, jbot, mobs, htop, jtop, hour;
    double ttop, dst;

    hour = msec / 3600000;
    mjdt = mjdy + hour / 24;
    hour = hour % 24 + 1;
    mobs = msec % 3600000;
    if (mobs <= 1800000) {
	ttop = (double) (mobs + 1800000) / 3.6e6;
	jtop = mjdt;
	if (hour > 1) {
	    jbot = mjdt;
	    htop = hour;
	    hbot = hour - 1;
	} else {
	    jbot = mjdt - 1;
	    htop = 1;
	    hbot = 24;
	}
    } else {
	ttop = (double) (mobs - 1800000) / 3.6e6;
	if (hour < 24) {
	    jtop = jbot = mjdt;
	    htop = hour + 1;
	    hbot = hour;
	} else {
	    jtop = mjdt + 1;
	    jbot = mjdt;
	    htop = 1;
	    hbot = 24;
	}
    }
	if (jbot < mjdl || jtop > mjdh) {
		*cerr = 50;
		fprintf(stderr, "SUBROUTINE INTDST -- ERROR CODE 50 -- T LIES OUTSIDE OF DST TABLE TIME SPAN -- ABORT\n");
		dst = -1e12;
	}
	else
		dst = ttop * dstx[(jtop - mjdl)*24 + (htop-1)] + (1. - ttop) * dstx[(jbot - mjdl)*24 + (hbot-1)];

	return (dst);
}

double intf107(int iyrl, int imol, int iyrh, int imoh, int iyr, int imon, int idom, int *idim, int msec, double *f107x, int *cerr) {

    int mbot, ybot, mtop, ytop;
    double tadd, thlf, tobs, tint, ttop, f107;

    /* Parameter adjustments */
    --idim;

    /* Function Body */
    thlf = (double) idim[imon] * .5;
    tobs = (double) (idom - 1) + (double) (msec) / 8.64e7;
    if (tobs <= thlf) {
	if (imon > 1) {
	    tadd = (double) idim[imon - 1] * .5;
	    tobs += tadd;
	    tint = thlf + tadd;
	    ttop = tobs / tint;
	    ytop = iyr;
	    ybot = iyr;
	    mtop = imon;
	    mbot = imon - 1;
	} else {
	    tobs += 15.5;
	    tint = thlf + 15.5;
	    ttop = tobs / tint;
	    ytop = iyr;
	    ybot = iyr - 1;
	    mtop = 1;
	    mbot = 12;
	}
    } else {
	if (imon < 12) {
	    tadd = (double) idim[imon + 1] * .5;
	    tobs -= thlf;
	    tint = thlf + tadd;
	    ttop = tobs / tint;
	    ytop = iyr;
	    ybot = iyr;
	    mtop = imon + 1;
	    mbot = imon;
	} else {
	    tobs += -15.5;
	    tint = thlf + 15.5;
	    ttop = tobs / tint;
	    ytop = iyr + 1;
	    ybot = iyr;
	    mtop = 1;
	    mbot = 12;
	}
    }
	if (ybot < iyrl || ytop > iyrh || ybot == iyrl && mbot < imol || ytop == iyrh && mtop > imoh) {
		fprintf(stderr, "SUBROUTINE INTF107 -- ERROR CODE 50 -- T LIES OUTSIDE OF F10.7 TABLE TIME SPAN -- ABORT\n");
		f107 = -1.;
		*cerr = 50;
	}
	else
		f107 = ttop * f107x[(ytop - iyrl)*12 + mtop-1] + (1. - ttop) * f107x[(ybot - iyrl)*12 + mbot-1];

	return (f107);
}

double getmut2(double thenmp, double phinmp, int iyear, int iday, int msec) {
    double gst, cth0, the0, phi0, sth0, eadj, sdec, cphd, sphd, cths, thes, phis, eopp, gmts, sths, slong, srasn;

    the0 = thenmp * D2R;
    phi0 = phinmp * D2R;
    cth0 = cos(the0);
    sth0 = sin(the0);
    gmts = (double) (msec) * 1e-3;
    sun2(iyear, iday, gmts, &gst, &slong, &srasn, &sdec);
    thes = (90. - sdec) * D2R;
    cths = cos(thes);
    sths = sin(thes);
    phis = (srasn - gst) * D2R;
    cphd = cos(phis - phi0);
    sphd = sin(phis - phi0);
    eopp = sths * sphd;
    eadj = cth0 * sths * cphd - sth0 * cths;
    return (12. - atan2(eopp, eadj) * R2D / 15.);
}

void sun2(int iyr, int iday, double secs, double *gst, double *slong, double *srasn, double *sdec) {
    double d__1, g, t, dj, vl, slp, fday, sined, obliq, cosined;

    if (iyr < 1901 || iyr > 2099) {
	*gst = 0.;
	*slong = 0.;
	*srasn = 0.;
	*sdec = 0.;
    } else {
	fday = secs / 86400.;
	dj = (double) (iyr - 1900) * 365. + (double) ((iyr - 1901) / 4) + (double) (iday) + fday - .5;
	t = dj / 36525.;
	d__1 = dj * .9856473354 + 279.696678;
	vl = d_mod(d__1, 360);
	d__1 = dj * .9856473354 + 279.690983 + fday * 360. + 180.;
	*gst = d_mod(d__1, 360);
	d__1 = dj * .985600267 + 358.475845;
	g = d_mod(d__1, 360) * D2R;
	*slong = vl + (1.91946 - t * .004789) * sin(g) + sin(g * 2.) * .020094;
	obliq = (23.45229 - t * .0130125) * D2R;
	slp = (*slong - .005686) * D2R;
	sined = sin(obliq) * sin(slp);
	cosined = sqrt(1. - sined * sined);
	*sdec = R2D * atan(sined / cosined);
	*srasn = 180. - R2D * atan2(1. / tan(obliq) * sined / cosined, -cos(slp) / cosined);
    }
}

void rmerge_(double *rmrg, double *rmlt) {
    double r1, r2, r3;

    r1 = rmrg[0];
    r2 = rmrg[1];
    r3 = rmrg[2];
    rmrg[0] = r1 * rmlt[0] + r2 * rmlt[3] + r3 * rmlt[6];
    rmrg[1] = r1 * rmlt[1] + r2 * rmlt[4] + r3 * rmlt[7];
    rmrg[2] = r1 * rmlt[2] + r2 * rmlt[5] + r3 * rmlt[8];
    r1 = rmrg[3];
    r2 = rmrg[4];
    r3 = rmrg[5];
    rmrg[3] = r1 * rmlt[0] + r2 * rmlt[3] + r3 * rmlt[6];
    rmrg[4] = r1 * rmlt[1] + r2 * rmlt[4] + r3 * rmlt[7];
    rmrg[5] = r1 * rmlt[2] + r2 * rmlt[5] + r3 * rmlt[8];
    r1 = rmrg[6];
    r2 = rmrg[7];
    r3 = rmrg[8];
    rmrg[6] = r1 * rmlt[0] + r2 * rmlt[3] + r3 * rmlt[6];
    rmrg[7] = r1 * rmlt[1] + r2 * rmlt[4] + r3 * rmlt[7];
    rmrg[8] = r1 * rmlt[2] + r2 * rmlt[5] + r3 * rmlt[8];
}

void tsearad(int full, int ks, int kr, int ns, int ng, double f, double *t, double *e, double *g) {
    int i, j, k;
    double s, z;

    /* Parameter adjustments */
    g -= (1 + ng * (1 + ns));
    --t;

    /* Function Body */
    r8vset(1, ng, 0., &e[0]);
    j = 1;
    s = 1.;
    r8vlinkt(1, 1, ng, s, &g[(j + ns) * ng + 1], &e[0]);
    for (i = 1; i <= ks; ++i) {
	++j;
	s = t[i + 1];
	r8vlinkt(1, 1, ng, s, &g[(j + ns) * ng + 1], &e[0]);
	if (full) {
	    ++j;
	    s = t[i + ks + 2];
	    r8vlinkt(1, 1, ng, s, &g[(j + ns) * ng + 1], &e[0]);
	}
    }
    z = 1.;
    for (k = 1; k <= kr; ++k) {
	j = 1;
	z = z * f / (double) k;
	r8vlinkt(1, 1, ng, z, &g[(j + (k + 1) * ns) * ng + 1], &e[0]);
	for (i = 1; i <= ks; ++i) {
	    ++j;
	    s = t[i + 1] * z;
	    r8vlinkt(1, 1, ng, s, &g[(j + (k + 1) * ns) * ng + 1], &e[0]);
	    if (full) {
		++j;
		s = t[i + ks + 2] * z;
		r8vlinkt(1, 1, ng, s, &g[(j + (k + 1) * ns) * ng + 1], &e[0]);
	    }
	}
    }
}

void tseardr(int full, int ks, int kr, int ns, int ng, double f, double *t, double *e, double *g) {
    int i, j, k;
    double s, z;

    /* Parameter adjustments */
    g -= (1 + ng * (1 + ns));
    --t;

    /* Function Body */
    r8vset(1, ng, 0., &e[0]);
    z = 1.;
    for (k = 1; k <= kr; ++k) {
	j = 1;
	r8vlinkt(1, 1, ng, z, &g[(j + (k + 1) * ns) * ng + 1], &e[0]);
	for (i = 1; i <= ks; ++i) {
	    ++j;
	    s = t[i + 1] * z;
	    r8vlinkt(1, 1, ng, s, &g[(j + (k + 1) * ns) * ng + 1], &e[0]);
	    if (full) {
		++j;
		s = t[i + ks + 2] * z;
		r8vlinkt(1, 1, ng, s, &g[(j + (k + 1) * ns) * ng + 1], &e[0]);
	    }
	}
	z = z * f / (double) k;
    }
}

void mseason(int ks, int ns, int ng, double d, double *t, double *e, double *g) {
    int i, j;
    double s;

    /* Parameter adjustments */
    g -= (1 + ng * (1 + ns));

    /* Function Body */
    r8vset(1, ng, 0., &e[0]);
    j = 1;
    s = 1.;
    r8vlinkt(1, 1, ng, s, &g[(j + ns) * ng + 1], &e[0]);
    r8vlinkt(1, 1, ng, d, &g[(j + (ns << 1)) * ng + 1], &e[0]);
    for (i = 1; i <= ks; ++i) {
	++j;
	s = t[i];
	r8vlinkt(1, 1, ng, s, &g[(j + ns) * ng + 1], &e[0]);
	s *= d;
	r8vlinkt(1, 1, ng, s, &g[(j + (ns << 1)) * ng + 1], &e[0]);
	++j;
	s = t[i + ks + 1];
	r8vlinkt(1, 1, ng, s, &g[(j + ns) * ng + 1], &e[0]);
	s *= d;
	r8vlinkt(1, 1, ng, s, &g[(j + (ns << 1)) * ng + 1], &e[0]);
    }
}

void iseason(int ks, int ns, int ng, double f, double *t, double *e, double *g) {
	int i, j;
	double s;

	r8vset(1, ng, 0., &e[0]);
	j = 0;
	r8vlinkt(1, 1, ng, f, &g[j * ng], &e[0]);
	for (i = 1; i <= ks; ++i) {
		++j;
		s = f * t[i];
		r8vlinkt(1, 1, ng, s, &g[j * ng], &e[0]);
		++j;
		s = f * t[i + ks + 1];
		r8vlinkt(1, 1, ng, s, &g[j * ng], &e[0]);
	}
}

void mpotent(int nmax, int mmax, int nd, int nz, double cphi, double sphi, double *d, double *z) {
    int m, n, id, iz, nd2;

    /* Parameter adjustments */
    z -= (1 + nz);
    --d;

    /* Function Body */
    nd2 = nd + nd;
    id = iz = 0;
    for (n = 1; n <= nmax; ++n) {
	++id;
	++iz;
	z[iz + nz] = d[id] * cphi;
	z[iz + (nz << 1)] = d[nd + id] * cphi;
	z[iz + nz * 3] = d[nd2 + id] * cphi;
	++iz;
	z[iz + nz] = d[id] * sphi;
	z[iz + (nz << 1)] = d[nd + id] * sphi;
	z[iz + nz * 3] = d[nd2 + id] * sphi;
	for (m = 1; m <= MIN(n,mmax); ++m) {
	    id += 2;
	    ++iz;
	    z[iz + nz] = d[id - 1] * cphi + d[id] * sphi;
	    z[iz + (nz << 1)] = d[nd + id - 1] * cphi + d[nd + id] * sphi;
	    z[iz + nz * 3] = d[nd2 + id - 1] * cphi + d[nd2 + id] * sphi;
	    ++iz;
	    z[iz + nz] = d[id] * cphi - d[id - 1] * sphi;
	    z[iz + (nz << 1)] = d[nd + id] * cphi - d[nd + id - 1] * sphi;
	    z[iz + nz * 3] = d[nd2 + id] * cphi - d[nd2 + id - 1] * sphi;
	    ++iz;
	    z[iz + nz] = d[id - 1] * cphi - d[id] * sphi;
	    z[iz + (nz << 1)] = d[nd + id - 1] * cphi - d[nd + id] * sphi;
	    z[iz + nz * 3] = d[nd2 + id - 1] * cphi - d[nd2 + id] * sphi;
	    ++iz;
	    z[iz + nz] = d[id] * cphi + d[id - 1] * sphi;
	    z[iz + (nz << 1)] = d[nd + id] * cphi + d[nd + id - 1] * sphi;
	    z[iz + nz * 3] = d[nd2 + id] * cphi + d[nd2 + id - 1] * sphi;
	}
    }
}

void jtabove(int pmin, int pmax, int nmax, int mmax, double r, double rref, int nz, double *z) {
    /* Initialized data */

    static double fgeo = 7.95774715459478e-4;

    /* Local variables */
    int m, n, p, iz;
    double ffac, fcur, fpsi, frmu, frpw, ztemp;

    /* Parameter adjustments */
    z -= (1 + nz);

    /* Function Body */
    frmu = rref / r;
    iz = 0;
    for (p = pmin; p <= pmax; ++p) {
	frpw = fgeo;
	for (n = 1; n <= nmax; ++n) {
	    ffac = frpw * (double) (n + n + 1);
	    fcur = ffac / (double) (n + 1);
	    fpsi = -(rref) * ffac / (double) (n * (n + 1));
	    ++iz;
	    ztemp = z[iz + nz];
	    z[iz + nz] = -fcur * z[iz + (nz << 1)];
	    z[iz + (nz << 1)] = fcur * ztemp;
	    z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    ++iz;
	    ztemp = z[iz + nz];
	    z[iz + nz] = -fcur * z[iz + (nz << 1)];
	    z[iz + (nz << 1)] = fcur * ztemp;
	    z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    for (m = 1; m <= MIN(n,mmax); ++m) {
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = -fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = -fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = -fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = -fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    }
	    frpw *= frmu;
	}
    }
}

void jtbelow(int pmin, int pmax, int nmax, int mmax, double r, double rref, int nz, double *z) {
    /* Initialized data */

    static double fgeo = 7.95774715459478e-4;

    /* Local variables */
    int m, n, p, iz;
    double ffac, frbg, fcur, fpsi, frmu, frpw, ztemp;

    /* Parameter adjustments */
    z -= (1 + nz);

    /* Function Body */
    frmu = r / rref;
    frbg = fgeo * (frmu * frmu * frmu);
    iz = 0;
    for (p = pmin; p <= pmax; ++p) {
	frpw = frbg;
	for (n = 1; n <= nmax; ++n) {
	    ffac = frpw * (double) (n + n + 1);
	    fcur = ffac / (double) n;
	    fpsi = -(rref) * ffac / (double) (n * (n + 1));
	    ++iz;
	    ztemp = z[iz + nz];
	    z[iz + nz] = fcur * z[iz + (nz << 1)];
	    z[iz + (nz << 1)] = -fcur * ztemp;
	    z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    ++iz;
	    ztemp = z[iz + nz];
	    z[iz + nz] = fcur * z[iz + (nz << 1)];
	    z[iz + (nz << 1)] = -fcur * ztemp;
	    z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    for (m = 1; m <= MIN(n,mmax); ++m) {
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fcur * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fcur * ztemp;
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    }
	    frpw *= frmu;
	}
    }
}

void jtbcont(int pmin, int pmax, int nmax, int mmax, double rold, double rnew, int nz, double *z) {
    int m, n, p, iz;
    double frbg, fcur, fpsi, frmu;

    /* Parameter adjustments */
    z -= (1 + nz);

    /* Function Body */
    frmu = rold / rnew;
    frbg = frmu * frmu;
    iz = 0;
    for (p = pmin; p <= pmax; ++p) {
	fpsi = frbg;
	for (n = 1; n <= nmax; ++n) {
	    fcur = fpsi * frmu;
	    ++iz;
	    z[iz + nz] = fcur * z[iz + nz];
	    z[iz + (nz << 1)] = fcur * z[iz + (nz << 1)];
	    z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    ++iz;
	    z[iz + nz] = fcur * z[iz + nz];
	    z[iz + (nz << 1)] = fcur * z[iz + (nz << 1)];
	    z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    for (m = 1; m <= MIN(n,mmax); ++m) {
		++iz;
		z[iz + nz] = fcur * z[iz + nz];
		z[iz + (nz << 1)] = fcur * z[iz + (nz << 1)];
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		z[iz + nz] = fcur * z[iz + nz];
		z[iz + (nz << 1)] = fcur * z[iz + (nz << 1)];
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		z[iz + nz] = fcur * z[iz + nz];
		z[iz + (nz << 1)] = fcur * z[iz + (nz << 1)];
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
		++iz;
		z[iz + nz] = fcur * z[iz + nz];
		z[iz + (nz << 1)] = fcur * z[iz + (nz << 1)];
		z[iz + nz * 3] = fpsi * z[iz + nz * 3];
	    }
	    fpsi *= frmu;
	}
    }
}

void mstream(int nmax, int mmax, int nd, int nz, double cphi, double sphi, double faor, double *d, double *z) {
    int m, n, id, iz;

    /* Parameter adjustments */
    z -= (1 + nz);
    --d;

    /* Function Body */
    id = iz = 0;
    for (n = 1; n <= nmax; ++n) {
	++id;
	++iz;
	z[iz + nz] = faor * d[nd + id] * cphi;
	z[iz + (nz << 1)] = -(faor) * d[id] * cphi;
	++iz;
	z[iz + nz] = faor * d[nd + id] * sphi;
	z[iz + (nz << 1)] = -(faor) * d[id] * sphi;
	for (m = 1; m <= MIN(n,mmax); ++m) {
	    id += 2;
	    ++iz;
	    z[iz + nz] = faor * (d[nd + id - 1] * cphi + d[nd + id] * sphi);
	    z[iz + (nz << 1)] = -(faor) * (d[id - 1] * cphi + d[id] * sphi);
	    ++iz;
	    z[iz + nz] = faor * (d[nd + id] * cphi - d[nd + id - 1] * sphi);
	    z[iz + (nz << 1)] = -(faor) * (d[id] * cphi - d[id - 1] * sphi);
	    ++iz;
	    z[iz + nz] = faor * (d[nd + id - 1] * cphi - d[nd + id] * sphi);
	    z[iz + (nz << 1)] = -(faor) * (d[id - 1] * cphi - d[id] * sphi);
	    ++iz;
	    z[iz + nz] = faor * (d[nd + id] * cphi + d[nd + id - 1] * sphi);
	    z[iz + (nz << 1)] = -(faor) * (d[id] * cphi + d[id - 1] * sphi);
	}
    }
}

void jpoloid(int pmin, int pmax, int nmax, int mmax, double r, double rm, int nd, int nz, double *t, double *d, double *z) {
    /* Initialized data */

    static double u0 = .0012566370614359158;

    /* Local variables */
    int m, n, p, id, iz, nd2;
    double fdeg, fhtj, frtj, cosp, sinp, ztemp;

    /* Parameter adjustments */
    z -= (1 + nz);
    --d;

    /* Function Body */
    nd2 = nd + nd;
    fhtj = 1. / rm / u0;
    frtj = rm / (r * r) / u0;
    iz = 0;
    for (p = pmin; p <= pmax; ++p) {
	id = 0;
	cosp = t[p];
	sinp = t[p + 1 + pmax];
	for (n = 1; n <= nmax; ++n) {
	    fdeg = frtj * (double) n;
	    ++id;
	    ++iz;
	    ztemp = z[iz + nz];
	    z[iz + nz] = fhtj * z[iz + (nz << 1)];
	    z[iz + (nz << 1)] = -fhtj * ztemp;
	    z[iz + nz * 3] = fdeg * d[nd2 + id] * cosp;
	    ++iz;
	    ztemp = z[iz + nz];
	    z[iz + nz] = fhtj * z[iz + (nz << 1)];
	    z[iz + (nz << 1)] = -fhtj * ztemp;
	    z[iz + nz * 3] = fdeg * d[nd2 + id] * sinp;
	    for (m = 1; m <= MIN(n,mmax); ++m) {
		id += 2;
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fhtj * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fhtj * ztemp;
		z[iz + nz * 3] = fdeg * (d[nd2 + id - 1] * cosp + d[nd2 + id] * sinp);
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fhtj * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fhtj * ztemp;
		z[iz + nz * 3] = fdeg * (d[nd2 + id] * cosp - d[nd2 + id - 1] * sinp);
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fhtj * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fhtj * ztemp;
		z[iz + nz * 3] = fdeg * (d[nd2 + id - 1] * cosp - d[nd2 + id] * sinp);
		++iz;
		ztemp = z[iz + nz];
		z[iz + nz] = fhtj * z[iz + (nz << 1)];
		z[iz + (nz << 1)] = -fhtj * ztemp;
		z[iz + nz * 3] = fdeg * (d[nd2 + id] * cosp + d[nd2 + id - 1] * sinp);
	    }
	}
    }
}

void blsgen(int nc, int nd, int ni, double *b, double *c, double *dldc) {
    int j;

    /* Parameter adjustments */
    dldc -= (1 + nd);
    --b;

    for (j = 1; j <= ni; ++j)
	b[j] += r8sdot(1, 1, nc, &dldc[j * nd + 1], &c[0]);
}

void getgmf(int nder, int ns, double *ep, double *tm, double *b, double *c, double *g, int *h, int *o, double *p) {
    /* Initialized data */

    static int null = 0;

    /* Local variables */
    int d, i, j, k, m, n, y, ic, la, lb, jc, ig, nb, ik, ni, im, nk, jm, no, js, nw;
    double gd, gm, bsum;

    /* Parameter adjustments */
    --p;
    --o;
    --h;
    --g;
    --c;
    --b;

    /* Function Body */
    ic = 1;
    ik = 1;
    for (i = 1; i <= ns; ++i) {
	g[i] = c[ic];
	ig = i;
	for (j = 1; j <= nder; ++j) {
	    ig += ns;
	    g[ig] = 0.;
	}
	n = o[i];
	if (n > 0) {
	    k = h[i];
	    if (*tm < p[ik] || *tm > p[ik + k + 1]) {
		fprintf(stderr, "SUBROUTINE GETGMF -- ERROR CODE 56 -- T LIES OUTSIDE OF KNOT DOMAIN -- ABORT\n");
		return;
	    }
	    m = n + 1;
	    nk = k + 2;
	    nb = n + k;
	    ni = nb + 1;
	    no = ni + 1;
	    nw = no + no;
	    r8slt(1, nk, *ep, &p[ik], &y);
	    la = MIN(nk,y+1);
	    r8slt(1, nk, *tm, &p[ik], &y);
	    lb = MIN(nk,y+1);
	    r8vset(1, nw, 0., &b[1]);
	    dbspln_(&la, ep, &m, &null, &k, &p[ik], &b[la - 1], &b[nw + 1]);
	    dbspln_(&lb, tm, &m, &null, &k, &p[ik], &b[no + lb - 1], &b[nw + 1]);
	    r8vsub(1, no+1, 1, no, &b[1], &b[1], &b[1]);
	    bsum = 0.;
	    gm = 0.;
	    jc = ic + nb;
	    for (j = ni; j >= 2; --j) {
		bsum += b[j];
		im = MIN(j,nk);
		jm = MAX(j-n,1);
		gm += (p[ik + im - 1] - p[ik + jm - 1]) * bsum * c[jc];
		--jc;
	    }
	    g[i] += gm / (double) n;
	    js = ic + lb - 1;
	    ig = i;
	    for (d = 0; d <= nder - 1; ++d) {
		ig += ns;
		dbspln_(&lb, tm, &n, &d, &k, &p[ik], &b[1], &b[nw + 1]);
		gd = 0.;
		jc = js;
		for (j = 1; j <= n; ++j) {
		    gd += b[j] * c[jc];
		    ++jc;
		}
		g[ig] = gd;
	    }
	    ic += nb;
	    ik += nk;
	}
	++ic;
    }
}

void dbspln_(int *l, double *t, int *n, int * d__, int *k, double *x, double *b, double *w) {
    /* Local variables */
    int i__, j, m, q, ik, jk, iw, lenb, posb, posw, posx;
    double fn, difi, difj, delx, temp;

    /* Parameter adjustments */
    --w;
    --b;
    --x;

    /* Function Body */
    q = *n - *d__;
    if (q == 1)
	b[1] = 1.;
    else {
	m = *l;
	ik = MIN(m,*k + 2);
	jk = MAX(m-1,1);
	difi = x[ik] - *t;
	delx = x[ik] - x[jk];
	if (delx == 0.)
	    b[q] = 0.;
	else
	    b[q] = 1. / delx;

	posb = q - 1;
	for (j = 2; j <= q; ++j) {
	    jk = MAX(m-j,1);
	    temp = difi * b[posb + 1];
	    delx = x[ik] - x[jk];
	    if (delx == 0.)
		temp = 0.;
	    else if (j < *n) 
		    temp /= delx;

	    b[posb] = temp;
	    --posb;
	}
	b[q + 1] = 0.;
	++m;
	for (i__ = 2; i__ <= q; ++i__) {
	    ik = MIN(m,*k + 2);
	    difi = x[ik] - *t;
	    posb = q;
	    for (j = i__; j <= q; ++j) {
		jk = MAX(m-j,1);
		difj = *t - x[jk];
		temp = difj * b[posb] + difi * b[posb + 1];
		delx = x[ik] - x[jk];
		if (delx == 0.)
		    temp = 0.;
		else if (j < *n)
			temp /= delx;

		b[posb] = temp;
		--posb;
	    }
	    ++m;
	}
    }
    posx = *l + *n - 1;
    posw = *d__ + *n;
    for (i__ = 1; i__ <= *n; ++i__) {
	lenb = MIN(q, posw - *d__);
	r8vset(1, posw, 0., &w[1]);
	r8vgathp(1, 1, *d__ + 1, lenb, &b[1], &w[1]);
	for (j = 1; j <= *d__; ++j) {
	    ik = posx;
	    jk = posx - q - j;
	    iw = posw;
	    fn = (double) (q + j - 1);
	    for (m = j; m <= *d__; ++m) {
		if (j < *d__) {
		    delx = x[MAX(1,MIN(ik,*k + 2))] - x[MAX(jk,1)];
		    if (delx == 0.)
			w[iw] = 0.;
		    else
			w[iw] = fn * (w[iw - 1] - w[iw]) / delx;

		} else
		    w[iw] = fn * (w[iw - 1] - w[iw]);

		--ik;
		--jk;
		--iw;
	    }
	}
	--posx;
	--posw;
    }
    r8vgathp(*d__ + 1, 1, 1, *n, &w[1], &b[1]);
}

void getgxf(int pmin, int pmax, int nmax, int mmax, int *ng, double *e, double *g, double *t) {

    /* Local variables */
    int m, n, p, ie, ig;
    double cosp, sinp;

    /* Parameter adjustments */
    --t;
    --g;
    --e;

    /* Function Body */
    r8vset(1, *ng, 0., &g[1]);
    ie = 0;
    for (p = pmin; p <= pmax; ++p) {
	ig = 1;
	cosp = t[p + 1];
	sinp = t[p + 2 + pmax];
	for (n = 1; n <= nmax; ++n) {
	    g[ig] = g[ig] + e[ie + 1] * cosp + e[ie + 2] * sinp;
	    ++ig;
	    ie += 2;
	    for (m = 1; m <= MIN(n,mmax); ++m) {
		g[ig] = g[ig] + (e[ie + 1] + e[ie + 3]) * cosp + (e[ie + 4] - e[ie + 2]) * sinp;
		++ig;
		g[ig] = g[ig] + (e[ie + 4] + e[ie + 2]) * cosp + (e[ie + 1] - e[ie + 3]) * sinp;
		++ig;
		ie += 4;
	    }
	}
    }
}

void bfield(int rgen, int nmxi, int nmxe, int nmni, int nmne, int mmxi, int mmxe, int mmni,
	int mmne, int grad, int ctyp, int dtyp, int ityp, int etyp, double ep, double re, 
	double rp, double rm, double tm, double clat, double elon, double h, double dst, double dstt, 
	double *rse, int *nc, int *na, double *ro, double *theta, int *atyp, int *dsti, int *bori, int *bkni, 
	double *bkpi, int *tdgi, int *dste, int *bore, int *bkne, double *bkpe, int *tdge, double *a, 
	double *b, double *c, double *p, double *r, double *t, int *u, double *w, double *dsdc, 
	double *dldc, double *dlda, int *cerr) {

    int ia, ie, ii, np, ns, nce, nci, nse, nsi, nmax, mmin, mmax;
    double phi;

    if (*cerr <= 49) {
	phi = elon;
	prebf_(&rgen, &ityp, &etyp, &dtyp, &grad, &nmni, &nmxi, &nmne, &nmxe, &mmni, &mmxi, &mmne, &mmxe, &nmax, &mmin, &mmax, &ns, &nsi, 
		&nse, nc, &nci, &nce, na, &np, &ii, &ie, &atyp[0], &dsti[0], &bori[0], &bkni[0], &tdgi[0], &dste[0], &bore[0], 
		&bkne[0], &tdge[0], &u[0], cerr);
	if (*cerr >= 50) return;
	if (*nc > 0) {
	    fdsdc_(&rgen, &ityp, &etyp, &nsi, &nse, nc, &nci, &ep, &tm, &dst, &dstt, &dsti[0], &bori[0], &bkni[0], &bkpi[0], &tdgi[0], 
		&dste[0], &bore[0], &bkne[0], &bkpe[0], &tdge[0], &u[0], &w[0], &dsdc[0], cerr);
	    if (*cerr >= 50) return;
	    fdlds_(&rgen, &grad, &ctyp, &clat, &phi, &h, &re, &rp, &rm, ro, &nsi, nc, &nci, &np, &ii, &ie, &nmni, &nmxi, &nmne, &nmxe, &nmax, 
		    &mmni, &mmxi, &mmne, &mmxe, &mmin, &mmax, theta, &p[0], &r[0], &t[0], &u[0], &w[0], &dldc[0], cerr);
	    if (*cerr >= 50) return;
	    if (rgen > 0) {
		rgen = 0;
		r8vset(1, grad * 36 + 28, 0., &b[0]);
		fdldc(grad, *nc, &dsdc[0], &dldc[0]);
		blgen(grad, *nc, &b[0], &c[0], &dldc[0]);
		bngen_(&b[0]);
	    }
	    if (dtyp == 2) {
		tec(grad, atyp[0], *nc, theta, &phi, &b[0], &dldc[0], &w[0]);
		tse(grad, atyp[1], *nc, &rse[0], &b[0], &dldc[0], &w[0]);
	    }
	}
	r8vgathp(1, 1, 15, 14, &b[0], &b[0]);
	if (grad == 1)
	    r8vgathp(29, 1, 47, 18, &b[0], &b[0]);

	ia = 0;
	if (*na > 0) {
	    r8vset(1, *na * 6, 0., &dlda[0]);
	    if (dtyp == 1)
		tbi_(&atyp[0], na, &ia, &a[0], &b[0], &dlda[0]);
	    else if (dtyp == 2) {
		tms(grad, atyp[2], *nc, *na, ia, &a[0], &b[0], &dldc[0], &dlda[0], &w[0]);
		tnm_(&grad, &atyp[3], nc, na, &ia, &a[0], &b[0], &dldc[0], &dlda[0], &w[0]);
		tvn_(&grad, &atyp[4], nc, na, &ia, &a[0], &b[0], &dldc[0], &dlda[0], &w[0]);
		tbi_(&atyp[5], na, &ia, &a[0], &b[0], &dlda[0]);
	    }
	}
    }
}

void prebf_(int *rgen, int *ityp, int *etyp, int *dtyp, int *grad, int *nmni, int *nmxi, int *
	nmne, int *nmxe, int *mmni, int *mmxi, int *mmne, int *mmxe, int *nmax, int *mmin, int *mmax, int *
	ns, int *nsi, int *nse, int *nc, int *nci, int *nce, int *na, int *np, int *ii, int *ie, int *
	atyp, int *dsti, int *bori, int *bkni, int *tdgi, int *dste, int *bore, int *bkne, int *tdge, int *u, int *cerr) {

    static int nx = 0;
    int i__1, edst, esvr, idst, isvr;

    /* Parameter adjustments */
    --u;
    --tdge;
    --bkne;
    --bore;
    --dste;
    --tdgi;
    --bkni;
    --bori;
    --dsti;
    --atyp;

    /* Function Body */
    if (*rgen == 1) {
	i__1 = MIN(MIN(*nmni,*nmxi), *nmne);
	if (MIN(i__1,*nmxe) < 0) {
		fprintf(stderr, "SUBROUTINE BFIELD -- ERROR CODE 50 -- NMNI, NMXI, NMNE, OR NMXE < 0 -- ABORT\n");
		return;
	}
	i__1 = MIN(MIN(*mmni,*mmxi), *mmne);
	if (MIN(i__1,*mmxe) < 0) {
		fprintf(stderr, "SUBROUTINE BFIELD -- ERROR CODE 51 -- MMNI, MMXI, MMNE, OR MMXE < 0 -- ABORT\n");
		return;
	}
	if (*mmni > *mmxi || *mmne > *mmxe) {
		fprintf(stderr, "SUBROUTINE BFIELD -- ERROR CODE 52 -- EITHER MMNI > MMXI OR MMNE > MMXE -- ABORT\n");
		return;
	}
	if (*mmxi > *nmxi || *mmxe > *nmxe) {
		fprintf(stderr, "SUBROUTINE BFIELD -- ERROR CODE 53 -- EITHER MMXI > NMXI OR MMXE > NMXE -- ABORT\n");
		return;
	}
	isvr = *ityp % 3;
	idst = *ityp / 3;
	esvr = *etyp % 3;
	edst = *etyp / 3;
	*nmax = MAX(*nmxi,*nmxe);
	*mmin = MIN(*mmni,*mmne);
	*mmax = MAX(*mmxi,*mmxe);
	*nsi = nshx(*nmxi, *nmni, *mmxi, *mmni);
	*nse = nshx(*nmxe, *nmne, *mmxe, *mmne);
	*ns = *nsi + *nse;
	*np = nlpx(*nmax, *mmax, *mmin);
	*ii = nlpx(*nmni - 1, *mmax, *mmin);
	*ie = nlpx(*nmne - 1, *mmax, *mmin);
	*nci = 0;
	if (*nsi > 0) {
	    i8vset(1, *nsi, 1, &u[1]);
	    if (isvr == 1)
		i8vadd(1, 1, 1, *nsi, &tdgi[1], &u[1], &u[1]);
	    else if (isvr == 2) {
		i8vadd(1, 1, 1, *nsi, &bori[1], &u[1], &u[1]);
		i8vadd(1, 1, 1, *nsi, &bkni[1], &u[1], &u[1]);
	    }
	    if (idst == 1)
		i8vadd(1, 1, 1, *nsi, &dsti[1], &u[1], &u[1]);

	    *nci = i8ssum(1, *nsi, &u[1]);
	}
	*nce = 0;
	if (*nse > 0) {
	    i__1 = *nsi + 1;
	    i8vset(i__1, *nse, 1, &u[1]);
	    if (esvr == 1)
		i8vadd(1, i__1, i__1, *nse, &tdge[1], &u[1], &u[1]);
	    else if (esvr == 2) {
		i8vadd(1, i__1, i__1, *nse, &bore[1], &u[1], &u[1]);
		i8vadd(1, i__1, i__1, *nse, &bkne[1], &u[1], &u[1]);
	    }
	    if (edst == 1)
		i8vadd(1, i__1, i__1, *nse, &dste[1], &u[1], &u[1]);

	    *nce = i8ssum(i__1, *nse, &u[1]);
	}
	*nc = *nci + *nce;
	*rgen = 7;
    }
    *rgen += nx;
    *na = 0;
    nx = 0;
    if (*dtyp == 1)
	*na += MIN(1,atyp[1]) * 3;
    else if (*dtyp == 2) {
	nx += atyp[1];
	nx += atyp[2];
	*na += MIN(1,atyp[3]) * 3;
	*na += MIN(1,atyp[4]) * 3;
	*na += MIN(1,atyp[5]) * 3;
	nx += *na;
	*na += MIN(1,atyp[6]) * 3;
    }
    nx = MIN(1,nx);
}

void fdlds_(int *rgen, int *grad, int *ctyp, double *clat, double *phi, double *h__, double *re, 
	double *rp, double *rm, double *ro, int *nsi, int *nc, int *nci, int *np, int *ii, int *ie, int *
	nmni, int *nmxi, int *nmne, int *nmxe, int *nmax, int *mmni, int *mmxi, int *mmne, int *mmxe, int *
	mmin, int *mmax, double *theta, double *p, double *r__, double *t, int *u, double *w, double *dldc, int *cerr) {
    /* Initialized data */

    static double roo = 0.;
    static double phio = 0.;
    static double thetao = 0.;
    static double clato = 0.;

    /* System generated locals */
    int i__1, i__2;

    /* Local variables */
    int m, n, ic, id, ip, lend, pgen, tgen;
    double fa, fc, fd, ar, fm, ra, fp, fr, fs, fn, fnm1, fnp1, fnp2, fnfp;
    double fprr, fdrr, pbppp, pbppr, pbrpp, pbtpp, pbppt, pbtpr, pbrpt, pbtpt, pbrpr, cscth2;
    double cscthe, costhe, cotthe, sinthe, fmfpst;

    /* Parameter adjustments */
    --dldc;
    --w;
    --u;
    --t;
    --r__;
    --p;

    /* Function Body */
    geocen_(ctyp, re, rp, rm, h__, clat, ro, theta, &sinthe, &costhe);
    pgen = *rgen - 6;
    tgen = pgen;
    if (phio != *phi) {
	pgen = 1;
	++(*rgen);
	phio = *phi;
    }
    if (thetao != *theta) {
	tgen = 1;
	++(*rgen);
	thetao = *theta;
    }
    if (clato != *clat) {
	++(*rgen);
	clato = *clat;
    }
    if (roo != *ro) {
	++(*rgen);
	roo = *ro;
    }
    if (*rgen > 0) {
	if (sinthe == 0.) {
	    if (*grad == 0)
		fprintf(stderr,"SUBROUTINE BFIELD -- ERROR CODE 1 -- GEOGRAPHIC POLAR POSITION DETECTED, B-PHI INDETERMINABLE -- WARNING\n");
	    else
		fprintf(stderr,"SUBROUTINE BFIELD -- ERROR CODE 2 -- GEOGRAPHIC POLAR POSITION DETECTED, B-PHI AND\n\t\t\t-- PHI-DERIVATIVE GRADIENT COMPONENTS INDETERMINABLE -- WARNING\n");

	    *phi = 0.;
	    cscthe = 0.;
	    cscth2 = 0.;
	    cotthe = 0.;
	} else {
	    cscthe = 1. / sinthe;
	    cscth2 = cscthe * cscthe;
	    cotthe = costhe * cscthe;
	}
	if (tgen > 0)
	    schmit_(grad, rgen, nmax, mmin, mmax, &sinthe, &costhe, &p[1], &r__[1]);

	if (pgen > 0)
	    trigmp(*mmax, *phi, &t[1]);

	r8vset(1, (*grad * 18 + 6) * *nc, 0., &dldc[1]);
	ic = 0;
	id = 1;
	ip = *ii;
	ar = *rm / *ro;
	i__1 = *nmni + 1;
	fa = pow_di(&ar, &i__1);
	for (n = *nmni; n <= *nmxi; ++n) {
	    fnp1 = (double) (n + 1);
	    fnp2 = (double) (n + 2);
	    fa *= ar;
	    for (m = *mmin; m <= MIN(n,*mmax); ++m) {
		++ip;
		if (m >= *mmni && m <= *mmxi) {
		    ++ic;
		    fm = (double) m;
		    fp = fa * p[ip];
		    fd = -fa * p[*np + ip];
		    fc = t[m + 1];
		    fs = t[*mmax + m + 2];
		    fnfp = fnp1 * fp;
		    fmfpst = fm * fp * cscthe;
		    lend = u[ic];
		    r8vset(id, u[ic], fd * fc, &dldc[1]);
		    r8vset(*nc + id, u[ic], fmfpst * fs, &dldc[1]);
		    r8vset((*nc << 1) + id, u[ic], fnfp * fc, &dldc[1]);
		    if (*grad == 1) {
			fprr = fp / *ro;
			fdrr = fd / *ro;
			pbtpt = -fa * p[(*np << 1) + ip] / *ro;
			pbtpp = -fm * fdrr * cscthe;
			pbtpr = -fnp2 * fdrr;
			pbppt = -fm * (fdrr + fprr * cotthe) * cscthe;
			pbppp = fm * fm * fprr * cscth2;
			pbppr = -fnp2 * fm * fprr * cscthe;
			pbrpt = -fnp1 * fdrr;
			pbrpp = -fnp1 * fm * fprr * cscthe;
			pbrpr = -fnp1 * fnp2 * fprr;
			r8vset(*nc * 6 + id, lend, pbtpt * fc, &dldc[1]);
			r8vset(*nc * 7 + id, lend, pbtpp * fs, &dldc[1]);
			r8vset((*nc << 3) + id, lend, pbtpr * fc, &dldc[1]);
			r8vset(*nc * 9 + id, lend, pbppt * fs, &dldc[1]);
			r8vset(*nc * 10 + id, lend, pbppp * fc, &dldc[1]);
			r8vset(*nc * 11 + id, lend, pbppr * fs, &dldc[1]);
			r8vset(*nc * 12 + id, lend, pbrpt * fc, &dldc[1]);
			r8vset(*nc * 13 + id, lend, pbrpp * fs, &dldc[1]);
			r8vset(*nc * 14 + id, lend, pbrpr * fc, &dldc[1]);
		    }
		    id += lend;
		    if (m > 0) {
			++ic;
			lend = u[ic];
			r8vset(id, lend, fd * fs, &dldc[1]);
			r8vset(*nc + id, lend, -fmfpst * fc, &dldc[1]);
			r8vset((*nc << 1) + id, lend, fnfp * fs, &dldc[1]);
			if (*grad == 1) {
			    r8vset(*nc * 6 + id, lend, pbtpt * fs, &dldc[1]);
			    r8vset(*nc * 7 + id, lend, -pbtpp * fc, &dldc[1]);
			    r8vset((*nc << 3) + id, lend, pbtpr * fs, &dldc[1]);
			    r8vset(*nc * 9 + id, lend, -pbppt * fc, &dldc[1]);
			    r8vset(*nc * 10 + id, lend, pbppp * fs, &dldc[1]);
			    r8vset(*nc * 11 + id, lend, -pbppr * fc, &dldc[1]);
			    r8vset(*nc * 12 + id, lend, pbrpt * fs, &dldc[1]);
			    r8vset(*nc * 13 + id, lend, -pbrpp * fc, &dldc[1]);
			    r8vset(*nc * 14 + id, lend, pbrpr * fs, &dldc[1]);
			}
			id += lend;
		    }
		}
	    }
	}
	ip = *ie;
	ra = *ro / *rm;
	i__2 = *nmne - 2;
	fr = pow_di(&ra, &i__2);
	for (n = *nmne; n <= *nmxe; ++n) {
	    fnm1 = (double) (n - 1);
	    fn = (double) n;
	    fr *= ra;
	    for (m = *mmin; m <= MIN(n,*mmax); ++m) {
		++ip;
		if (m >= *mmne && m <= *mmxe) {
		    ++ic;
		    fm = (double) m;
		    fp = fr * p[ip];
		    fd = -fr * p[*np + ip];
		    fc = t[m + 1];
		    fs = t[*mmax + m + 2];
		    fnfp = -fn * fp;
		    fmfpst = fm * fp * cscthe;
		    lend = u[ic];
		    r8vset(id, lend, fd * fc, &dldc[1]);
		    r8vset(*nc + id, lend, fmfpst * fs, &dldc[1]);
		    r8vset((*nc << 1) + id, lend, fnfp * fc, &dldc[1]);
		    if (*grad == 1) {
			fprr = fp / *ro;
			fdrr = fd / *ro;
			pbtpt = -fr * p[(*np << 1) + ip] / *ro;
			pbtpp = -fm * fdrr * cscthe;
			pbtpr = fnm1 * fdrr;
			pbppt = -fm * (fdrr + fprr * cotthe) * cscthe;
			pbppp = fm * fm * fprr * cscth2;
			pbppr = fnm1 * fm * fprr * cscthe;
			pbrpt = fn * fdrr;
			pbrpp = fn * fm * fprr * cscthe;
			pbrpr = -fn * fnm1 * fprr;
			r8vset(*nc * 6 + id, lend, pbtpt * fc, &dldc[1]);
			r8vset(*nc * 7 + id, lend, pbtpp * fs, &dldc[1]);
			r8vset((*nc << 3) + id, lend, pbtpr * fc, &dldc[1]);
			r8vset(*nc * 9 + id, lend, pbppt * fs, &dldc[1]);
			r8vset(*nc * 10 + id, lend, pbppp * fc, &dldc[1]);
			r8vset(*nc * 11 + id, lend, pbppr * fs, &dldc[1]);
			r8vset(*nc * 12 + id, lend, pbrpt * fc, &dldc[1]);
			r8vset(*nc * 13 + id, lend, pbrpp * fs, &dldc[1]);
			r8vset(*nc * 14 + id, lend, pbrpr * fc, &dldc[1]);
		    }
		    id += lend;
		    if (m > 0) {
			++ic;
			lend = u[ic];
			r8vset(id, lend, fd * fs, &dldc[1]);
			r8vset(*nc + id, lend, -fmfpst * fc, &dldc[1]);
			r8vset((*nc << 1) + id, lend, fnfp * fs, &dldc[1]);
			if (*grad == 1) {
			    r8vset(*nc * 6 + id, lend, pbtpt * fs, &dldc[1]);
			    r8vset(*nc * 7 + id, lend, -pbtpp * fc, &dldc[1]);
			    r8vset((*nc << 3) + id, lend, pbtpr * fs, &dldc[1]);
			    r8vset(*nc * 9 + id, lend, -pbppt * fc, &dldc[1]);
			    r8vset(*nc * 10 + id, lend, pbppp * fs, &dldc[1]);
			    r8vset(*nc * 11 + id, lend, -pbppr * fc, &dldc[1]);
			    r8vset(*nc * 12 + id, lend, pbrpt * fs, &dldc[1]);
			    r8vset(*nc * 13 + id, lend, -pbrpp * fc, &dldc[1]);
			    r8vset(*nc * 14 + id, lend, pbrpr * fs, &dldc[1]);
			}
			id += lend;
		    }
		}
	    }
	}
	tdc(*grad, *nc, *clat, *theta, &dldc[1], &w[1]);
    }
}

void geocen_(int *ctyp, double *re, double *rp, double *rm, double *h, double *clat, double *r, double *theta, double *sinthe, double *costhe) {

    int ifirst = 1;
    double re2, rp2, kappa, rhoew, rhons, costh2, sinth2;

    *theta = *clat;
    *r = *rm + *h;
    *sinthe = sin(*theta);
    *costhe = cos(*theta);
    if (*ctyp == 0) {
	if (ifirst == 1) {
	    ifirst = 0;
	    re2 = *re * *re;
	    rp2 = *rp * *rp;
	}
	sinth2 = *sinthe * *sinthe;
	costh2 = *costhe * *costhe;
	kappa = sqrt(re2 * sinth2 + rp2 * costh2);
	rhoew = re2 / kappa + *h;
	rhons = rp2 / kappa + *h;
	*theta = atan2(rhoew * *sinthe, rhons * *costhe);
	*r = sqrt(rhoew * rhoew * sinth2 + rhons * rhons * costh2);
	*sinthe = sin(*theta);
	*costhe = cos(*theta);
    }
}

void schmit_(int *grad, int *rgen, int *nmax, int *mmin, int *mmax, double *sinthe, double *costhe, double *p, double *r) {

    int l, n, np, kd0, kd1, kd2, kp0, kp1, kp2, kq2, kq1, kq0, ksm2, ktm2, ksec, ktes, knnp, nd0sec;
    int np1sec, nd0tes, nd1tes, np1tes, np2tes, nq0nnp, nq0msq;
    double cscth2, costh2, sinth2, cscthe, cotthe, cthsth;
    double root3 = 1.732050807568877;

    /* Parameter adjustments */
    --r;
    --p;

    /* Function Body */
    if (*rgen > 6)
	srecur_(grad, nmax, mmin, mmax, &ksm2, &ktm2, &np, &np1sec, &nd0sec, &np1tes, &np2tes, &nd0tes, &nd1tes, &nq0nnp, &nq0msq, &r[1]);
 
    if (*nmax >= 1) {
	kp0 = 1;
	kp2 = kp0;
	if (*mmin <= 0) {
	    p[kp0] = *costhe;
	    p[np + kp0] = -(*sinthe);
	    if (*grad == 1)
		p[(np << 1) + kp0] = -(*costhe);

	    ++kp0;
	}
	if (*mmax >= 1) {
	    p[kp0] = *sinthe;
	    p[np + kp0] = *costhe;
	    if (*grad == 1)
		p[(np << 1) + kp0] = -(*sinthe);

	    ++kp0;
	}
	if (*nmax >= 2) {
	    kp1 = kp0;
	    sinth2 = *sinthe * *sinthe;
	    costh2 = *costhe * *costhe;
	    cthsth = *costhe * *sinthe;
	    if (*mmin <= 0) {
		p[kp0] = (costh2 * 3. - 1.) / 2.;
		p[np + kp0] = cthsth * -3.;
		if (*grad == 1) {
		    p[(np << 1) + kp0] = (costh2 * 2. - 1.) * -3.;
		}
		++kp0;
	    }
	    if (*mmin <= 1 && *mmax >= 1) {
		p[kp0] = root3 * cthsth;
		p[np + kp0] = root3 * (costh2 * 2. - 1.);
		if (*grad == 1) {
		    p[(np << 1) + kp0] = root3 * -4. * cthsth;
		}
		++kp0;
	    }
	    if (*mmax >= 2) {
		p[kp0] = root3 * sinth2 / 2.;
		p[np + kp0] = root3 * cthsth;
		if (*grad == 1) {
		    p[(np << 1) + kp0] = root3 * (costh2 * 2. - 1.);
		}
		++kp0;
	    }
	    kd2 = np + kp2;
	    kd1 = np + kp1;
	    kd0 = np + kp0;
	    kq2 = np + kd2;
	    kq1 = np + kd1;
	    kq0 = np + kd0;
	    ksec = 1;
	    ktes = 1;
	    knnp = 1;
	    if (*sinthe == 0.) {
		for (n = 3; n <= *nmax; ++n) {
		    l = MAX(0, MIN(n-1,*mmax) - *mmin + 1);
		    if (l > 0) {
			r8vset(kp0, l, 0., &p[1]);
			r8vlinkq(kp1, np1tes + ktes, kp0, l, *costhe, &p[1], &r[1], &p[1]);
			r8vlinkq(kp2, np2tes + ktes, kp0, l, -1., &p[1], &r[1], &p[1]);
			r8vset(kd0, l, 0., &p[1]);
			r8vlinkq(kd1, np1tes + ktes, kd0, l, *costhe, &p[1], &r[1], &p[1]);
			r8vlinkq(kd2, np2tes + ktes, kd0, l, -1., &p[1], &r[1], &p[1]);
			if (*grad == 1) {
			    r8vset(kq0, l, 0., &p[1]);
			    r8vlinkq(kq1, np1tes + ktes, kq0, l, *costhe, &p[1], &r[1], &p[1]);
			    r8vlinkq(kp1, np1tes + ktes, kq0, l, -(*costhe), &p[1], &r[1], &p[1]);
			    r8vlinkq(kq2, np2tes + ktes, kq0, l, -1., &p[1], &r[1], &p[1]);
			}
			ktes += l;
		    }
		    if (n <= *mmax) {
			p[kp0 + l] = 0.;
			p[kd0 + l] = 0.;
			if (*grad == 1)
			    p[kq0 + l] = 0.;
			++l;
		    }
		    kp2 = kp1;
		    kp1 = kp0;
		    kp0 += l;
		    kd2 = kd1;
		    kd1 = kd0;
		    kd0 += l;
		    kq2 = kq1;
		    kq1 = kq0;
		    kq0 += l;
		}
	    } else {
		cotthe = *costhe / *sinthe;
		cscthe = 1. / *sinthe;
		cscth2 = cscthe * cscthe;
		for (n = 3; n <= *nmax; ++n) {
		    l = MAX(0, MIN(n-1,*mmax) - *mmin + 1);
		    if (l > 0) {
			r8vset(kp0, l, 0., &p[1]);
			r8vlinkq(kp1, np1tes + ktes, kp0, l, *costhe, &p[1], &r[1], &p[1]);
			r8vlinkq(kp2, np2tes + ktes, kp0, l, -1., &p[1], &r[1], &p[1]);
			r8vset(kd0, l, 0., &p[1]);
			r8vlinkq(kp0, nd0tes + ktes, kd0, l, cotthe, &p[1], &r[1], &p[1]);
			r8vlinkq(kp1, nd1tes + ktes, kd0, l, -cscthe, &p[1], &r[1], &p[1]);
			if (*grad == 1) {
			    r8vset(kq0, l, 0., &p[1]);
			    r8vlinkq(kp0, nq0msq + ktm2, kq0, l, cscth2, &p[1], &r[1], &p[1]);
			    r8vlinkt(kp0, kq0, l, -r[nq0nnp + knnp], &p[1], &p[1]);
			    r8vlinkt(kd0, kq0, l, -cotthe, &p[1], &p[1]);
			}
			ktes += l;
		    }
		    if (n <= *mmax) {
			p[kp0 + l] = r[np1sec + ksec] * *sinthe * p[kp0 - 1];
			p[kd0 + l] = r[nd0sec + ksec] * cotthe * p[kp0 + l];
			if (*grad == 1)
			    p[kq0 + l] = (r[nq0msq - ksm2 + n + 1] * cscth2 -r[nq0nnp + knnp]) * p[kp0 + l] - cotthe * p[kd0 + l];

			++ksec;
			++l;
		    }
		    ++knnp;
		    kp2 = kp1;
		    kp1 = kp0;
		    kp0 += l;
		    kd0 += l;
		    kq0 += l;
		}
	    }
	}
    }
}

void srecur_(int *grad, int *nmax, int *mmin, int *mmax, int *ksm2, int *ktm2, int *npall, int *
	nad1, int *nad2, int *nad3, int *nad4, int *nad5, int *nad6, int *nad7, int *nad8, double *r) {
    int m, n, ksec, kmin, lmax, kmax, ktes, knnp, kmsq, nnnp1, nsect, ntess;
    double fn, f2n, fnl1, fnp1, f2nl1, fnsq, fmsq, fnl1sq, fdsqrt;

    /* Parameter adjustments */
    --r;

    /* Function Body */
    lmax = MIN(*nmax,2);
    kmax = MIN(*mmax,2);
    kmin = MIN(*mmin,2);
    *ksm2 = MIN(*mmin,3);
    *ktm2 = I_DIM(*mmin, 3) + 1;
    *npall = nlpx(*nmax, *mmax, *mmin);
    ntess = *npall - nlpx(lmax, kmax, kmin) + kmax - *mmax;
    nsect = MAX(0, *mmax - 2);
    nnnp1 = MAX(0, *nmax - 2);
    *nad1 = 0;
    *nad2 = nsect;
    *nad3 = nsect + *nad2;
    *nad4 = ntess + *nad3;
    *nad5 = ntess + *nad4;
    *nad6 = ntess + *nad5;
    *nad7 = ntess + *nad6;
    *nad8 = nnnp1 + *nad7;
    ksec = ktes = knnp = 0;
    for (n = 3; n <= *nmax; ++n) {
	fnp1 = (double) (n + 1);
	fn = (double) n;
	fnl1 = (double) (n - 1);
	f2n = fn * 2.;
	f2nl1 = f2n - 1.;
	fnsq = fn * fn;
	fnl1sq = fnl1 * fnl1;
	if (n <= *mmax) {
	    ++ksec;
	    r[*nad1 + ksec] = sqrt(f2nl1 / f2n);
	    r[*nad2 + ksec] = fn;
	}
	if (*grad == 1) {
	    ++knnp;
	    r[*nad7 + knnp] = fn * fnp1;
	}
	for (m = *mmin; m <= MIN(n-1,*mmax); ++m) {
	    ++ktes;
	    fmsq = (double)(m * m);
	    fdsqrt = sqrt(fnsq - fmsq);
	    r[*nad3 + ktes] = f2nl1 / fdsqrt;
	    r[*nad4 + ktes] = sqrt(fnl1sq - fmsq) / fdsqrt;
	    r[*nad5 + ktes] = fn;
	    r[*nad6 + ktes] = fdsqrt;
	}
    }
    if (*grad == 1) {
	kmsq = 0;
	for (m = *ksm2; m <= *mmax; ++m) {
	    ++kmsq;
	    r[*nad8 + kmsq] = (double)(m * m);
	}
    }
}

void trigmp(int mmax, double phi, double *t) {
    int m;

    /* Parameter adjustments */
    --t;

    t[1] = 1.;
    t[mmax + 2] = 0.;
    if (mmax > 0) {
	t[2] = cos(phi);
	t[mmax + 3] = sin(phi);
	for (m = 2; m <= mmax; ++m) {
	    t[m + 1] = t[2] * 2. * t[m] - t[m - 1];
	    t[mmax + m + 2] = t[2] * 2. * t[mmax + m + 1] - t[mmax + m];
	}
    }
}

void tdc(int grad, int nc, double clat, double theta, double *dldc, double *r) {
    double psi, cpsi, spsi;

    psi = theta - clat;
    spsi = sin(psi);
    cpsi = cos(psi);
    r[0] = -cpsi;
    r[1] = 0.;
    r[2] = -spsi;
    r[3] = 0.;
    r[4] = 1.;
    r[5] = 0.;
    r[6] = spsi;
    r[7] = 0.;
    r[8] = -cpsi;
    ltranv(1, nc, nc, &r[0], &dldc[0]);
    if (grad == 1) {
	ltranv(0, nc * 3, nc * 3, &r[0], &dldc[nc * 6]);
	ltranv(0, nc, nc, &r[0], &dldc[nc * 6]);
	ltranv(0, nc, nc, &r[0], &dldc[nc * 9]);
	ltranv(0, nc, nc, &r[0], &dldc[nc * 12]);
    }
}

void fdsdc_(int *rgen, int *ityp, int *etyp, int *nsi, int *nse, int *nc, int *nci, double *ta,
	double *tb, double *dst, double *dstt, int *dsti, int *bori, int *bkni, double *bkpi, int *tdgi, 
	int *dste, int *bore, int *bkne, double *bkpe, int *tdge, int *u, double *w, double *dsdc, int *cerr) {

    static double tbo = 0.;

    /* System generated locals */
    int i__1;

    /* Local variables */
    int tgen, edst, idst, esvr, isvr;

    /* Parameter adjustments */
    --dsdc;
    --w;
    --u;
    --tdge;
    --bkpe;
    --bkne;
    --bore;
    --dste;
    --tdgi;
    --bkpi;
    --bkni;
    --bori;
    --dsti;

    /* Function Body */
    tgen = MAX(0,*rgen - 6);
    if (tbo != *tb) {
	tgen = MIN(1,tgen + *ityp + *etyp);
	*rgen += tgen;
	tbo = *tb;
    }
    if (tgen > 0) {
	r8vset(1, *nc << 1, 0., &dsdc[1]);
	if (*nsi > 0) {
	    isvr = *ityp % 3;
	    idst = *ityp / 3;
	    i8vcum(1, 1, *nsi, &u[1]);
	    r8vscats(1, *nsi, 1., &u[1], &dsdc[1]);
	    r8vscats(1, *nsi, 0., &u[1], &dsdc[*nc + 1]);
	    i8vadds(1, 1, *nsi, 1, &u[1], &u[1]);
	    if (isvr == 1)
		taylor(*nc, *nsi, *ta, *tb, &tdgi[1], &u[1], &w[1], &dsdc[1]);
	    else if (isvr == 2) {
		bsplyn(*nc, *nsi, ta, tb, &bori[1], &bkni[1], &bkpi[1], &u[1], &w[1], &dsdc[1], *cerr);
		if (*cerr >= 50) goto L10;
	    }
	    if (idst == 1)
		dstorm(*nc, *nsi, dst, dstt, &dsti[1], &u[1], &dsdc[1]);

L10:
	    i8vdel(1, 1, *nsi, &u[1]);
	}
	if (*nse > 0) {
	    esvr = *etyp % 3;
	    edst = *etyp / 3;
	    i__1 = *nsi + 1;
	    i8vcum(1, i__1, *nse, &u[1]);
	    r8vscats(i__1, *nse, 1., &u[1], &dsdc[*nci + 1]);
	    r8vscats(i__1, *nse, 0., &u[1], &dsdc[*nc + *nci + 1]);
	    i8vadds(i__1, i__1, *nse, 1, &u[1], &u[1]);
	    if (esvr == 1)
		taylor(*nc, *nse, *ta, *tb, &tdge[1], &u[*nsi + 1], &w[1], &dsdc[*nci + 1]);
	    else if (esvr == 2) {
		bsplyn(*nc, *nse, ta, tb, &bore[1], &bkne[1], &bkpe[1], &u[*nsi + 1], &w[1], &dsdc[*nci + 1], *cerr);
		if (*cerr >= 50) goto L20;
	    }
	    if (edst == 1)
		dstorm(*nc, *nse, dst, dstt, &dste[1], &u[*nsi + 1], &dsdc[*nci + 1]);

L20:
	    i8vdel(1, *nsi + 1, *nse, &u[1]);
	}
    }
}

void taylor(int nc, int ns, double ta, double tb, int *tdeg, int *u, double *dsdt, double *dsdc) {
    int i, j, n, iu;
    double dt;

    /* Parameter adjustments */
    --dsdt;
    --u;
    --tdeg;

    /* Function Body */
    dt = tb - ta;
    for (i = 1; i <= ns; ++i) {
	n = tdeg[i];
	if (n > 0) {
	    iu = u[i];
	    dsdt[1] = 1.;
	    for (j = 1; j <= n; ++j) {
		dsdt[j + 1] = dsdt[j] * dt / (double) j;
	    }
	    r8vgathp(2, 1, iu, n, &dsdt[1], &dsdc[0]);
	    r8vgathp(1, 1, nc + iu, n, &dsdt[1], &dsdc[0]);
	    u[i] += n;
	}
    }
}

void bsplyn(int nc, int ns, double *ta, double *tb, int *bord, int *bkno, double *bkpo, int *u, double *dtdb, double *dsdc, int cerr) {
    int i, k, l, m, n, ik, iu;

    /* Parameter adjustments */
    --dsdc;
    --dtdb;
    --u;
    --bkpo;
    --bkno;
    --bord;

    /* Function Body */
    ik = 1;
    for (i = 1; i <= ns; ++i) {
	n = bord[i];
	k = bkno[i];
	l = n + k;
	iu = u[i];
	if (n > 0) {
	    m = n + 1;
	    sbspln_(ta, tb, &m, &k, &bkpo[ik], &dtdb[1], &dsdc[iu], &cerr);
	    if (cerr >= 50) return;
	    r8vset(1, l + 1, 0., &dtdb[1]);
	    tbspln_(tb, &n, &k, &bkpo[ik], &dtdb[1], &cerr);
	    if (cerr >= 50) return;
	    r8vgathp(1, 1, nc + iu, l, &dtdb[1], &dsdc[1]);
	} else if (k > 0) {
	    r8vset(iu, l, 0., &dsdc[1]);
	    r8vset(nc + iu, l, 0., &dsdc[1]);
	}
	u[i] += l;
	ik = ik + k + 2;
    }
}

void sbspln_(double *ta, double *tb, int *n, int *k, double *bkpo, double *dtdb, double *dsdc, int *cerr) {
    int i, ik, jk, ip, nl, np, ns;
    double rn;

    /* Parameter adjustments */
    --dsdc;
    --dtdb;
    --bkpo;

    /* Function Body */
    if (*n > 1) {
	nl = *n + *k + 1;
	r8vset(1, nl << 1, 0., &dtdb[1]);
	tbspln_(tb, n, k, &bkpo[1], &dtdb[1], cerr);
	if (*cerr >= 50) return;
	tbspln_(ta, n, k, &bkpo[1], &dtdb[nl + 1], cerr);
	if (*cerr >= 50) return;
	r8vsub(nl+1, 1, 1, nl, &dtdb[1], &dtdb[1], &dtdb[1]);
	rn = 1. / (double) (*n - 1);
	np = *n + *k - 1;
	ns = np;
	for (i = 1; i <= np; ++i) {
	    ip = i + 1;
	    ik = MIN(ip,*k + 2);
	    jk = MAX(ip - *n + 1,1);
	    dsdc[i] = (bkpo[ik] - bkpo[jk]) * r8ssum_(&ip, &ns, &dtdb[1]);
	    --ns;
	}
	if (np > 0)
	    r8vscale(1, np, rn, &dsdc[1]);
    }
}

void tbspln_(double *t, int *n, int *k, double *bkpo, double *dtdb, int *cerr) {
    int i__, j, l, m, p, y, ik, jk, posb;
    double difi, difj, delk, temp;

    /* Parameter adjustments */
    --dtdb;
    --bkpo;

    /* Function Body */
    if (*t >= bkpo[1] && *t <= bkpo[*k + 2]) {
	r8slt(1, *k + 2, *t, &bkpo[1], &y);
	l = MIN(*k+2,y+1);
	p = l + *n - 2;
	if (*n == 1)
	    dtdb[p] = 1.;
	else if (*n > 1) {
	    m = l;
	    ik = MIN(m,*k+2);
	    jk = MAX(m-1,1);
	    difi = bkpo[ik] - *t;
	    delk = bkpo[ik] - bkpo[jk];
	    if (delk == 0.)
		dtdb[p] = 0.;
	    else
		dtdb[p] = 1. / delk;

	    posb = p - 1;
	    for (j = 2; j <= *n; ++j) {
		jk = MAX(m-j,1);
		temp = difi * dtdb[posb + 1];
		delk = bkpo[ik] - bkpo[jk];
		if (delk == 0.)
		    temp = 0.;
		else if (j < *n)
			temp /= delk;

		dtdb[posb] = temp;
		--posb;
	    }
	    dtdb[p + 1] = 0.;
	    ++m;
	    for (i__ = 2; i__ <= *n; ++i__) {
		ik = MIN(m,*k+2);
		difi = bkpo[ik] - *t;
		posb = p;
		for (j = i__; j <= *n; ++j) {
		    jk = MAX(m-j,1);
		    difj = *t - bkpo[jk];
		    temp = difj * dtdb[posb] + difi * dtdb[posb + 1];
		    delk = bkpo[ik] - bkpo[jk];
		    if (delk == 0.)
			temp = 0.;
		    else if (j < *n)
			temp /= delk;

		    dtdb[posb] = temp;
		    --posb;
		}
		++m;
	    }
	}
    } else
	fprintf (stderr, "SUBROUTINE TBSPLN -- ERROR CODE 54 -- T LIES OUTSIDE OF KNOT DOMAIN -- ABORT\n");
}

void dstorm(int nc, int ns, double *dst, double *dstt, int *dstm, int *u, double *dsdc) {
    int i, n, iu;

    /* Parameter adjustments */
    --u;
    --dstm;

    for (i = 1; i <= ns; ++i) {
	n = dstm[i];
	if (n > 0) {
	    iu = u[i];
	    r8vset(iu, n, *dst, &dsdc[0]);
	    r8vset(nc + iu, n, *dstt, &dsdc[0]);
	    u[i] += n;
	}
    }
}

void fdldc(int grad, int nc, double *dsdc, double *dldc) {
    int i__1, i, j;

    i = 1;
    for (j = 0; j < 3; ++j) {
	r8vmul(nc+1, i, nc * 3 + i, nc, &dsdc[0], &dldc[0], &dldc[0]);
	i += nc;
    }
    i = 1;
    for (j = 0; j < 3; ++j) {
	r8vmul(1, i, i, nc, &dsdc[0], &dldc[0], &dldc[0]);
	i += nc;
    }
    if (grad == 1) {
	i = 1;
	for (j = 0; j < 9; ++j) {
	    r8vmul(nc+1, nc * 6 + i, nc * 15 + i, nc, &dsdc[0], &dldc[0], &dldc[0]);
	    i += nc;
	}
	i = 1;
	for (j = 0; j < 9; ++j) {
	    i__1 = nc * 6 + i;
	    r8vmul(1, i__1, i__1, nc, &dsdc[0], &dldc[0], &dldc[0]);
	    i += nc;
	}
    }
}

void blgen(int grad, int nc, double *b, double *c, double *dldc) {
    int i, j;

    i = 1;
    for (j = 0; j < 6; ++j) {
	b[j] += r8sdot(i, 1, nc, &dldc[0], &c[0]);
	i += nc;
    }
    if (grad == 1) {
	i = 1;
	for (j = 28; j < 46; ++j) {
	    b[j] += r8sdot(nc * 6 + i, 1, nc, &dldc[0], &c[0]);
	    i += nc;
	}
    }
}

void bngen_(double *b) {
    double cd, cf, ch, ci, cx, cy, cz, cdt, cft, cht, cit, cxt, cyt, czt;

    cx = b[0];
    cy = b[1];
    cz = b[2];
    cxt = b[3];
    cyt = b[4];
    czt = b[5];
    ch = sqrt(cx * cx + cy * cy);
    cf = sqrt(ch * ch + cz * cz);
    if (ch != 0.) {
	cd = atan(cy / (ch + cx)) * 2.;
	cdt = (cx * cyt - cy * cxt) / ch / ch;
	cht = (cx * cxt + cy * cyt) / ch;
    } else {
	cd = cdt = cht = 0.;
    }
    if (cf != 0.) {
	ci = atan(cz / (cf + ch)) * 2.;
	cit = (ch * czt - cz * cht) / cf / cf;
	cft = (ch * cht + cz * czt) / cf;
    } else {
	ci = cit = cft = 0.;
    }
    b[6] = cd;
    b[7] = ci;
    b[8] = ch;
    b[9] = cf;
    b[10] = cdt;
    b[11] = cit;
    b[12] = cht;
    b[13] = cft;
}

void tec(int grad, int k, int nc, double *theta, double *phi, double *b, double *dldc, double *r) {
    int i__1;

    /* Local variables */
    double cphi, sphi, costhe, sinthe;

    /* Parameter adjustments */
    --b;

    if (k >= 1) {
	sinthe = sin(*theta);
	costhe = cos(*theta);
	sphi = sin(*phi);
	cphi = cos(*phi);
	r[0] = -costhe * cphi;
	r[1] = -sphi;
	r[2] = -sinthe * cphi;
	r[3] = -costhe * sphi;
	r[4] = cphi;
	r[5] = -sinthe * sphi;
	r[6] = sinthe;
	r[7] = 0.;
	r[8] = -costhe;
	ltrans(1, 1, &b[1], &r[0], &b[1]);
	ltrans(1, 1, &b[4], &r[0], &b[4]);
	ltranv(1, nc, nc, &r[0], &dldc[0]);
	ltranv(0, nc, nc, &r[0], &dldc[nc * 3]);
	bngen_(&b[1]);
	if (grad == 1) {
	    ltranv(0, 3, 3, &r[0], &b[29]);
	    ltranv(0, 3, 3, &r[0], &b[38]);
	    ltrans(1, 1, &b[29], &r[0], &b[29]);
	    ltrans(1, 1, &b[32], &r[0], &b[32]);
	    ltrans(1, 1, &b[35], &r[0], &b[35]);
	    ltrans(1, 1, &b[38], &r[0], &b[38]);
	    ltrans(1, 1, &b[41], &r[0], &b[41]);
	    ltrans(1, 1, &b[44], &r[0], &b[44]);
	    i__1 = nc * 3;
	    ltranv(0, i__1, i__1, &r[0], &dldc[nc * 6]);
	    ltranv(0, i__1, i__1, &r[0], &dldc[nc * 15]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 6]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 9]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 12]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 15]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 18]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 21]);
	}
    }
}

void tse(int grad, int k, int nc, double *rse, double *b, double *dldc, double *r) {
    int i__1;

    if (k >= 1) {
	r8vgathp(1, 1, 1, 9, &rse[0], &r[0]);
	ltrans(1, 1, &b[0], &r[0], &b[0]);
	ltrans(1, 1, &b[3], &r[0], &b[3]);
	ltranv(1, nc, nc, &r[0], &dldc[0]);
	ltranv(0, nc, nc, &r[0], &dldc[nc * 3]);
	bngen_(&b[0]);
	if (grad == 1) {
	    ltranv(0, 3, 3, &r[0], &b[28]);
	    ltranv(0, 3, 3, &r[0], &b[37]);
	    ltrans(1, 1, &b[28], &r[0], &b[28]);
	    ltrans(1, 1, &b[31], &r[0], &b[31]);
	    ltrans(1, 1, &b[34], &r[0], &b[34]);
	    ltrans(1, 1, &b[37], &r[0], &b[37]);
	    ltrans(1, 1, &b[40], &r[0], &b[40]);
	    ltrans(1, 1, &b[43], &r[0], &b[43]);
	    i__1 = nc * 3;
	    ltranv(0, i__1, i__1, &r[0], &dldc[nc * 6]);
	    ltranv(0, i__1, i__1, &r[0], &dldc[nc * 15]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 6]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 9]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 12]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 15]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 18]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 21]);
	}
    }
}

void tms(int grad, int k, int nc, int na, int ia, double *a, double *b, double *dldc, double *dlda, double *r) {
    int i__1;
    double eulx, euly, eulz, ceulx, ceuly, ceulz, seulx, seuly, seulz;

    if (k >= 1) {
	eulx = a[ia];
	euly = a[ia + 1];
	eulz = a[ia + 2];
	seulx = sin(eulx);
	ceulx = cos(eulx);
	seuly = sin(euly);
	ceuly = cos(euly);
	seulz = sin(eulz);
	ceulz = cos(eulz);
	fdldeu_(&k, &na, &ia, &seulx, &ceulx, &seuly, &ceuly, &seulz, &ceulz, &r[0], &b[1], &dlda[0]);
	r[0] = ceuly * ceulz;
	r[1] = -seulz;
	r[2] = -seuly * ceulz;
	r[3] = ceuly * ceulx * seulz + seuly * seulx;
	r[4] = ceulx * ceulz;
	r[5] = ceuly * seulx - seuly * seulz * ceulx;
	r[6] = -ceuly * seulx * seulz + seuly * ceulx;
	r[7] = -seulx * ceulz;
	r[8] = ceuly * ceulx + seuly * seulx * seulz;
	ltrans(1, 1, &b[0], &r[0], &b[0]);
	ltrans(1, 1, &b[3], &r[0], &b[3]);
	ltranv(1, nc, nc, &r[0], &dldc[0]);
	ltranv(0, nc, nc, &r[0], &dldc[nc * 3]);
	ltranv(0, na, ia, &r[0], &dlda[0]);
	ltranv(0, na, ia, &r[0], &dlda[na * 3]);
	bngen_(&b[1]);
	if (grad == 1) {
	    ltranv(0, 3, 3, &r[0], &b[28]);
	    ltranv(0, 3, 3, &r[0], &b[37]);
	    ltrans(1, 1, &b[28], &r[0], &b[28]);
	    ltrans(1, 1, &b[31], &r[0], &b[31]);
	    ltrans(1, 1, &b[34], &r[0], &b[34]);
	    ltrans(1, 1, &b[37], &r[0], &b[37]);
	    ltrans(1, 1, &b[40], &r[0], &b[40]);
	    ltrans(1, 1, &b[43], &r[0], &b[43]);
	    i__1 = nc * 3;
	    ltranv(0, i__1, i__1, &r[0], &dldc[nc * 6]);
	    ltranv(0, i__1, i__1, &r[0], &dldc[nc * 15]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 6]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 9]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 12]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 15]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 18]);
	    ltranv(0, nc, nc, &r[0], &dldc[nc * 21]);
	}
	ia += 3;
    }
}

void fdldeu_(int *k, int *na, int *ia, double *seulx, double *ceulx, double *seuly, double *ceuly, 
	double *seulz, double *ceulz, double *r, double *b, double *dlda) {

    int i, j;

    if (*k == 1) {
	i = *ia;
	for (j = 1; j <= 6; ++j) {
	    dlda[i] = 0.;
	    dlda[i + 1] = 0.;
	    dlda[i + 2] = 0.;
	    i += *na;
	}
    } else {
	r[0] = 0.;
	r[1] = 0.;
	r[2] = 0.;
	r[3] = -(*ceuly) * *seulx * *seulz + *seuly * *ceulx;
	r[4] = -(*seulx) * *ceulz;
	r[5] = *ceuly * *ceulx + *seuly * *seulz * *seulx;
	r[6] = -(*ceuly) * *ceulx * *seulz - *seuly * *seulx;
	r[7] = -(*ceulx) * *ceulz;
	r[8] = -(*ceuly) * *seulx + *seuly * *ceulx * *seulz;
	ltrans(*na, 1, &b[0], &r[0], &dlda[*ia]);
	ltrans(*na, 1, &b[3], &r[0], &dlda[*na * 3 + *ia]);
	r[0] = -(*seuly) * *ceulz;
	r[1] = 0.;
	r[2] = -(*ceuly) * *ceulz;
	r[3] = -(*seuly) * *ceulx * *seulz + *ceuly * *seulx;
	r[4] = 0.;
	r[5] = -(*seuly) * *seulx - *ceuly * *seulz * *ceulx;
	r[6] = *seuly * *seulx * *seulz + *ceuly * *ceulx;
	r[7] = 0.;
	r[8] = -(*seuly) * *ceulx + *ceuly * *seulx * *seulz;
	ltrans(*na, 1, &b[0], &r[0], &dlda[*ia + 1]);
	ltrans(*na, 1, &b[3], &r[0], &dlda[*na * 3 + *ia + 1]);
	r[0] = -(*ceuly) * *seulz;
	r[1] = -(*ceulz);
	r[2] = *seuly * *seulz;
	r[3] = *ceuly * *ceulx * *ceulz;
	r[4] = -(*ceulx) * *seulz;
	r[5] = -(*seuly) * *ceulz * *ceulx;
	r[6] = -(*ceuly) * *seulx * *ceulz;
	r[7] = *seulx * *seulz;
	r[8] = *seuly * *seulx * *ceulz;
	ltrans(*na, 1, &b[0], &r[0], &dlda[*ia + 2]);
	ltrans(*na, 1, &b[3], &r[0], &dlda[*na * 3 + *ia + 2]);
    }
}

void tnm_(int *grad, int *k, int *nc, int *na, int *ia, double *a, double *b, double *dldc, double *dlda, double *r) {
    int i__1;
    double chix, chiy, chiz, cchix, cchiy, cchiz, schix, schiy, schiz;

    if (*k >= 1) {
	chix = a[*ia];
	chiy = a[*ia + 1];
	chiz = a[*ia + 2];
	schix = sin(chix);
	cchix = cos(chix);
	schiy = sin(chiy);
	cchiy = cos(chiy);
	schiz = sin(chiz);
	cchiz = cos(chiz);
	fdldno_(k, na, ia, &schix, &cchix, &schiy, &cchiy, &schiz, &cchiz, &r[0], &b[0], &dlda[0]);
	r[0] = 1.;
	r[1] = 0.;
	r[2] = 0.;
	r[3] = schix;
	r[4] = cchix;
	r[5] = 0.;
	r[6] = schiy * cchiz;
	r[7] = schiy * schiz;
	r[8] = cchiy;
	ltrans(1, 1, &b[0], &r[0], &b[0]);
	ltrans(1, 1, &b[3], &r[0], &b[3]);
	ltranv(1, *nc, *nc, &r[0], &dldc[0]);
	ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 3]);
	ltranv(0, *na, *ia, &r[0], &dlda[0]);
	ltranv(0, *na, *ia, &r[0], &dlda[*na * 3]);
	bngen_(&b[0]);
	if (*grad == 1) {
	    ltranv(0, 3, 3, &r[0], &b[28]);
	    ltranv(0, 3, 3, &r[0], &b[37]);
	    ltrans(1, 1, &b[28], &r[0], &b[28]);
	    ltrans(1, 1, &b[31], &r[0], &b[31]);
	    ltrans(1, 1, &b[34], &r[0], &b[34]);
	    ltrans(1, 1, &b[37], &r[0], &b[37]);
	    ltrans(1, 1, &b[40], &r[0], &b[40]);
	    ltrans(1, 1, &b[43], &r[0], &b[43]);
	    i__1 = *nc * 3;
	    ltranv(0, i__1, i__1, &r[0], &dldc[*nc * 6]);
	    ltranv(0, i__1, i__1, &r[0], &dldc[*nc * 15]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 6]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 9]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 12]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 15]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 18]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 21]);
	}
	*ia += 3;
    }
}

void fdldno_(int *k, int *na, int *ia, double *schix, double *cchix, double *schiy, double *cchiy, 
	double *schiz, double *cchiz, double *r, double *b, double *dlda) {

    int i, j;

    if (*k == 1) {
	i = *ia;
	for (j = 1; j <= 6; ++j) {
	    dlda[i] = 0.;
	    dlda[i + 1] = 0.;
	    dlda[i + 2] = 0.;
	    i += *na;
	}
    } else {
	r[0] = r[1] = r[2] = 0.;
	r[3] = *cchix;
	r[4] = -(*schix);
	r[5] = r[6] = r[7] = r[8] = 0.;
	ltrans(*na, 1, &b[0], &r[0], &dlda[*ia]);
	ltrans(*na, 1, &b[3], &r[0], &dlda[*na * 3 + *ia]);
	r[0] = r[1] = r[2] = r[3] = r[4] = r[5] = 0.;
	r[6] = *cchiy * *cchiz;
	r[7] = *cchiy * *schiz;
	r[8] = -(*schiy);
	ltrans(*na, 1, &b[0], &r[0], &dlda[*ia + 1]);
	ltrans(*na, 1, &b[3], &r[0], &dlda[*na * 3 + *ia + 1]);
	r[0] = r[1] = r[2] = r[3] = r[4] = r[5] = 0.;
	r[6] = -(*schiy) * *schiz;
	r[7] = *schiy * *cchiz;
	r[8] = 0.;
	ltrans(*na, 1, &b[0], &r[0], &dlda[*ia + 2]);
	ltrans(*na, 1, &b[3], &r[0], &dlda[*na * 3 + *ia + 2]);
    }
}

void tvn_(int *grad, int *k, int *nc, int *na, int *ia, double *a, double *b, double *dldc, double *dlda, double *r) {
    int i__1;

    /* Local variables */
    double slpx, slpy, slpz;

    if (*k >= 1) {
	slpx = a[*ia];
	slpy = a[*ia + 1];
	slpz = a[*ia + 2];
	fdldsl_(k, na, ia, &b[0], &dlda[0]);
	r[0] = slpx;
	r[1] = 0.;
	r[2] = 0.;
	r[3] = 0.;
	r[4] = slpy;
	r[5] = 0.;
	r[6] = 0.;
	r[7] = 0.;
	r[8] = slpz;
	ltrans(1, 1, &b[0], &r[0], &b[0]);
	ltrans(1, 1, &b[3], &r[0], &b[3]);
	ltranv(1, *nc, *nc, &r[0], &dldc[0]);
	ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 3]);
	ltranv(0, *na, *ia, &r[0], &dlda[0]);
	ltranv(0, *na, *ia, &r[0], &dlda[*na * 3]);
	bngen_(&b[0]);
	if (*grad == 1) {
	    ltranv(0, 3, 3, &r[0], &b[28]);
	    ltranv(0, 3, 3, &r[0], &b[37]);
	    ltrans(1, 1, &b[28], &r[0], &b[28]);
	    ltrans(1, 1, &b[31], &r[0], &b[31]);
	    ltrans(1, 1, &b[34], &r[0], &b[34]);
	    ltrans(1, 1, &b[37], &r[0], &b[37]);
	    ltrans(1, 1, &b[40], &r[0], &b[40]);
	    ltrans(1, 1, &b[43], &r[0], &b[43]);
	    i__1 = *nc * 3;
	    ltranv(0, i__1, i__1, &r[0], &dldc[*nc * 6]);
	    ltranv(0, i__1, i__1, &r[0], &dldc[*nc * 15]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 6]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 9]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 12]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 15]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 18]);
	    ltranv(0, *nc, *nc, &r[0], &dldc[*nc * 21]);
	}
	*ia += 3;
    }
}

void fdldsl_(int *k, int *na, int *ia, double *b, double *dlda) {
    int i, j;

    i = *ia;
    for (j = 0; j < 6; ++j) {
	dlda[i] = 0.;
	dlda[i + 1] = 0.;
	dlda[i + 2] = 0.;
	i += *na;
    }
    if (*k > 1) {
	i = *ia;
	dlda[i] = b[0];
	i += *na;
	dlda[i + 1] = b[1];
	i += *na;
	dlda[i + 2] = b[2];
	i += *na;
	dlda[i] = b[3];
	i += *na;
	dlda[i + 1] = b[4];
	i += *na;
	dlda[i + 2] = b[5];
    }
}

void tbi_(int *k, int *na, int *ia, double *a, double *b, double *dlda) {
    double biax, biay, biaz;

    if (*k >= 1) {
	biax = a[*ia];
	biay = a[*ia + 1];
	biaz = a[*ia + 2];
	fdldbi_(k, na, ia, &dlda[0]);
	b[0] += biax;
	b[1] += biay;
	b[2] += biaz;
	bngen_(&b[0]);
	*ia += 3;
    }
}

void fdldbi_(int *k, int *na, int *ia, double *dlda) {
    int i, j;

    i = *ia;
    for (j = 0; j < 6; ++j) {
	dlda[i] = 0.;
	dlda[i + 1] = 0.;
	dlda[i + 2] = 0.;
	i += *na;
    }
    if (*k > 1) {
	i = *ia;
	dlda[i] = 1.;
	i += *na;
	dlda[i + 1] = 1.;
	i += *na;
	dlda[i + 2] = 1.;
    }
}

void ltrans(int n, int m, double *q, double *r, double *s) {
    double q1, q2, q3;

    q1 = q[0];
    q2 = q[m];
    q3 = q[m + m];
    s[0] = q1 * r[0] + q2 * r[1] + q3 * r[2];
    s[n] = q1 * r[3] + q2 * r[4] + q3 * r[5];
    s[n + n] = q1 * r[6] + q2 * r[7] + q3 * r[8];
}

void ltranv(int rfac, int n, int m, double *r, double *v) {
    /* System generated locals */
    int i__1;

    /* Parameter adjustments */
    --r;

    /* Function Body */
    if (m > 0) {
	if (rfac == 1) {
	    r[10] = r[4] / r[1];
	    r[11] = r[5] - r[2] * r[10];
	    r[12] = r[6] - r[3] * r[10];
	    r[13] = r[7] / r[1];
	    r[14] = (r[8] - r[2] * r[13]) / r[11];
	    r[15] = r[9] - r[3] * r[13] - r[12] * r[14];
	    r[13] -= r[10] * r[14];
	}
	r8vscale(1, m, r[1], &v[0]);
	r8vlinkt(n+1, 1, m, r[2], &v[0], &v[0]);
	r8vlinkt(n + n + 1, 1, m, r[3], &v[0], &v[0]);
	i__1 = n + 1;
	r8vscale(i__1, m, r[11], &v[0]);
	r8vlinkt(1, i__1, m, r[10], &v[0], &v[0]);
	i__1 = n + n + 1;
	r8vlinkt(i__1, n+1, m, r[12], &v[0], &v[0]);
	r8vscale(i__1, m, r[15], &v[0]);
	r8vlinkt(1, i__1, m, r[13], &v[0], &v[0]);
	r8vlinkt(n+1, i__1, m, r[14], &v[0], &v[0]);
    }
}

int nshx(int nmax, int nmin, int mmax, int mmin) {
	int ret_val, i__2, i__5, i__6, kmax;

	kmax = mmax + 1;
	i__5 = MIN(nmin,mmin);
	i__6 = MIN(nmin,kmax);
	i__2 = kmax * kmax - mmin * mmin + i__5 * i__5 - i__6 * i__6 + (nmax - mmax - I_DIM(nmin, kmax)) * 
		((mmax << 1) + 1) + (I_DIM(nmin, mmin) - nmax + mmin - 1) * MAX(0, (mmin << 1) - 1);
	ret_val = MAX(0,i__2);
	return ret_val;
}

int nlpx(int nmax, int mmax, int mmin) {
    int mdif;

    mdif = MAX(0, MIN(nmax,mmax) - mmin + 1);
    return(mdif * (mdif + 1) / 2 + mdif * I_DIM(nmax, mmax) + mmin - 1);
}

int i8ssum(int abeg, int alen, int *a) {
    int i, aadr, ret_val;

    /* Parameter adjustments */
    --a;

    ret_val = 0;
    aadr = abeg;
    for (i = 0; i < alen; ++i)
	ret_val += a[aadr++];

    return ret_val;
}

void i8vset(int abeg, int alen, int s, int *a) {
    int i, aadr;

    /* Parameter adjustments */
    --a;

    /* Function Body */
    aadr = abeg;
    for (i = 1; i <= alen; ++i)
	a[aadr++] = s;
}

void i8vadd(int abeg, int bbeg, int cbeg, int vlen, int *a, int *b, int *c) {
    int i, aadr, badr, cadr;

    /* Parameter adjustments */
    --c;
    --b;
    --a;

    /* Function Body */
    aadr = abeg;
    badr = bbeg;
    cadr = cbeg;
    for (i = 0; i < vlen; ++i)
	c[cadr++] = b[badr++] + a[aadr++];
}

void i8vadds(int abeg, int bbeg, int vlen, int s, int *a, int *b) {
    int i, aadr, badr;

    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    aadr = abeg;
    badr = bbeg;
    for (i = 0; i < vlen; ++i)
	b[badr++] = a[aadr++] + s;
}

void i8vcum(int abas, int abeg, int alen, int *a) {
    int i, aadr, acur, aprv;

    /* Parameter adjustments */
    --a;

    aprv = a[abeg];
    a[abeg] = abas;
    aadr = abeg + 1;
    for (i = 1; i <= alen - 1; ++i) {
	acur = a[aadr];
	a[aadr] = a[aadr - 1] + aprv;
	aprv = acur;
	++aadr;
    }
}

void i8vdel(int abas, int abeg, int alen, int *a) {
    int i, aadr, acur, aprv;

    /* Parameter adjustments */
    --a;

    aprv = abas;
    aadr = abeg;
    for (i = 1; i <= alen; ++i) {
	acur = a[aadr];
	a[aadr] = acur - aprv;
	aprv = acur;
	++aadr;
    }
}

void r8vset(int abeg, int alen, double s, double *a) {
    int i, aadr;

    /* Parameter adjustments */
    --a;

    aadr = abeg;
    for (i = 0; i < alen; ++i)
	a[aadr++] = s;
}

double r8sdot(int abeg, int bbeg, int vlen, double *a, double *b) {
    double ret_val;
    int i, aadr, badr;

    /* Parameter adjustments */
    --b;
    --a;

    ret_val = 0.;
    aadr = abeg;
    badr = bbeg;
    for (i = 0; i < vlen; ++i)
	ret_val += a[aadr++] * b[badr++];
 
    return ret_val;
}

double r8ssum_(int *abeg, int *alen, double *a) {
    double ret_val;
    int i, aadr;

    /* Parameter adjustments */
    --a;

    /* Function Body */
    ret_val = 0.;
    aadr = *abeg;
    for (i = 1; i <= *alen; ++i) {
	ret_val += a[aadr];
	++aadr;
    }
    return ret_val;
}

void r8slt(int abeg, int alen, double s, double *a, int *j) {
    int i, aadr;

    /* Parameter adjustments */
    --a;

    /* Function Body */
    aadr = abeg;
    for (i = 1; i <= alen; ++i) {
	if (s < a[aadr]) {
	    *j = i - 1;
	    return;
	}
	++aadr;
    }
    *j = alen;
}

void r8vsub(int abeg, int bbeg, int cbeg, int vlen, double *a, double *b, double *c) {
    int i, aadr, badr, cadr;

    /* Parameter adjustments */
    --c;
    --b;
    --a;

    /* Function Body */
    aadr = abeg;
    badr = bbeg;
    cadr = cbeg;
    for (i = 1; i <= vlen; ++i)
	c[cadr++] = b[badr++] - a[aadr++];
}

void r8vmul(int abeg, int bbeg, int cbeg, int vlen, double *a, double *b, double *c) {
    int i, aadr, badr, cadr;

    /* Parameter adjustments */
    --c;
    --b;
    --a;

    aadr = abeg;
    badr = bbeg;
    cadr = cbeg;
    for (i = 0; i < vlen; ++i)
	c[cadr++] = b[badr++] * a[aadr++];
}

void r8vscale(int abeg, int alen, double s, double *a) {
    int i, aadr;

    /* Parameter adjustments */
    --a;

    aadr = abeg;
    for (i = 0; i < alen; ++i) {
	a[aadr] = s * a[aadr];
	++aadr;
    }
}

void r8vscats(int qbeg, int qlen, double s, int *q, double *a) {
    int i, qadr;

    /* Parameter adjustments */
    --a;
    --q;

    qadr = qbeg;
    for (i = 1; i <= qlen; ++i)
	a[q[qadr++]] = s;

}

void r8vlinkt(int abeg, int bbeg, int vlen, double s, double *a, double *b) {
    int i, aadr, badr;

    /* Parameter adjustments */
    --b;
    --a;

    aadr = abeg;
    badr = bbeg;
    for (i = 1; i <= vlen; ++i)
	b[badr++] += s * a[aadr++];
}

void r8vlinkq(int abeg, int bbeg, int cbeg, int vlen, double s, double *a, double *b, double *c) {
    int i, aadr, badr, cadr;

    /* Parameter adjustments */
    --c;
    --b;
    --a;

    aadr = abeg;
    badr = bbeg;
    cadr = cbeg;
    for (i = 1; i <= vlen; ++i)
	c[cadr++] += s * a[aadr++] * b[badr++];
}

void r8vgathp(int abeg, int ainc, int bbeg, int blen, double *a, double *b) {
    int i, aadr, badr;

    /* Parameter adjustments */
    --b;	--a;

    aadr = abeg;
    badr = bbeg;
    for (i = 0; i < blen; ++i) {
	b[badr++] = a[aadr];
	aadr += ainc;
    }
}

double d_mod(double x, double y) {
	double quotient;
	if( (quotient = x / y) >= 0)
		quotient = floor(quotient);
	else
		quotient = -floor(-quotient);
	return(x - y * quotient );
}

double pow_di(double *ap, int *bp) {
	double pow, x;
	int n;
	unsigned long u;

	pow = 1;
	x = *ap;
	n = *bp;

	if(n != 0) {
		if(n < 0) {
			n = -n;
			x = 1/x;
		}
		for(u = n; ; ) {
			if(u & 01)
				pow *= x;
			if(u >>= 1)
				x *= x;
			else
				break;
		}
	}
	return(pow);
}

int i_dnnt(double x) {
	return (int)(x >= 0. ? floor(x + .5) : -floor(.5 - x));
}
