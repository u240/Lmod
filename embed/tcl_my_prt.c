#define _GNU_SOURCE
#include <tcl/tcl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int PrintStrObjCmd(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
{
  char     *str;
  int      len;
  Tcl_Obj *objPtr;
  int i;
  if (objc != 2) {
    Tcl_WrongNumArgs(interp, 1, objv, "value");
    return TCL_ERROR;
  }
  objPtr = objv[1];

  str = Tcl_GetStringFromObj(objPtr, &len);
  if (str[0] == '\0')
    return TCL_ERROR;

  printf("len: %d, str: %s\n", len, str);
  return TCL_OK;
}

int Tcl_AppInit(Tcl_Interp* interp)
{
  if (Tcl_Init(interp) == TCL_ERROR)
    return TCL_ERROR;
  Tcl_CreateObjCommand(interp,"prtstr", PrintStrObjCmd, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
  return TCL_OK;
}

int main(int argc, char **argv)
{
  Tcl_Obj    *argvPtr;
  Tcl_FindExecutable(argv[1]);

  Tcl_Interp *interp = Tcl_CreateInterp();
  Tcl_AppInit(interp);

  Tcl_SetVar2Ex(interp, "argv0", NULL, NewNativeObj(argv[1],-1), TCL_GLOBAL_ONLY);
  argc -= 2;
  argv += 2;
  Tcl_SetVar2Ex(interp, "argc", NULL, Tcl_NewIntObj(argc), TCL_GLOBAL_ONLY);
  argvPtr = Tcl_NewListObj(0, NULL);
  while (argc--) {
    Tcl_ListObjAppendElement(NULL, argvPtr, NewNativeObj(*argv++, -1));

  Tcl_EvalFile(interp, argv[1]);

  exit(0);
}

