#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llvm-c/Core.h"
#include "llvm-c/ExecutionEngine.h"
#include "llvm-c/Transforms/Scalar.h"
#include "llvm-c/Transforms/IPO.h"
#include "llvm-c/Target.h"
#include "llvm-c/Initialization.h"

#include "erl_nif.h"

typedef enum {
//  @@TYPES@@
// -- Start generating from Target_8h.xml on {{2011,6,29},{23,3,15}}--

RTLLVMByteOrdering,
RTLLVMTargetDataRef,
RTLLVMStructLayoutRef,
// --- Stop generating from Target_8h.xml

// -- Start generating from Scalar_8h.xml on {{2011,6,29},{23,3,15}}--

// --- Stop generating from Scalar_8h.xml

// -- Start generating from Initialization_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from Initialization_8h.xml

// -- Start generating from IPO_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from IPO_8h.xml

// -- Start generating from ExecutionEngine_8h.xml on {{2011,6,29},{23,3,14}}--

RTLLVMGenericValueRef,
RTLLVMExecutionEngineRef,
// --- Stop generating from ExecutionEngine_8h.xml

// -- Start generating from Core_8h.xml on {{2011,6,29},{23,3,14}}--

RTLLVMAttribute,
RTLLVMOpcode,
RTLLVMTypeKind,
RTLLVMLinkage,
RTLLVMVisibility,
RTLLVMCallConv,
RTLLVMIntPredicate,
RTLLVMRealPredicate,
RTLLVMBool,
RTLLVMContextRef,
RTLLVMModuleRef,
RTLLVMTypeRef,
RTLLVMTypeHandleRef,
RTLLVMValueRef,
RTLLVMBasicBlockRef,
RTLLVMBuilderRef,
RTLLVMModuleProviderRef,
RTLLVMMemoryBufferRef,
RTLLVMPassManagerRef,
RTLLVMPassRegistryRef,
RTLLVMUseRef,
// --- Stop generating from Core_8h.xml

} llvm_type_t;

typedef struct llvm_ptr {
  llvm_type_t type;
  void *value;
} llvm_ptr_t;

// @@RESOURCE_TYPES@@
// -- Start generating from Target_8h.xml on {{2011,6,29},{23,3,15}}--

// --- Stop generating from Target_8h.xml

// -- Start generating from Scalar_8h.xml on {{2011,6,29},{23,3,15}}--

// --- Stop generating from Scalar_8h.xml

// -- Start generating from Initialization_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from Initialization_8h.xml

// -- Start generating from IPO_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from IPO_8h.xml

// -- Start generating from ExecutionEngine_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from ExecutionEngine_8h.xml

// -- Start generating from Core_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from Core_8h.xml

static ErlNifResourceType* module;

static int load_nif(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info) {
  module = enif_open_resource_type(env, "llvm_nif", "module", NULL,
				   ERL_NIF_RT_CREATE, NULL);
  return 0;
}

static int llvm_ptr_deref(ErlNifEnv* env, ERL_NIF_TERM term, void** objp) {
  llvm_ptr_t *ptr;
  enif_get_resource(env, term, module, (void **) &ptr);
  //  printf("fetching %ld\n",(long)ptr->value);
  *objp = ptr->value;
  return 0;
}

static ERL_NIF_TERM llvm_ptr_create(ErlNifEnv* env, llvm_type_t type,
				    void *data) {
  ERL_NIF_TERM term;
  llvm_ptr_t *ptr = (llvm_ptr_t*) enif_alloc_resource(module,
						      sizeof(llvm_ptr_t));

  //  printf("storing %ld\n",(long)data);
  /* initialize struct ... */
  ptr->type = type;
  ptr->value = data;

  term = enif_make_resource(env, ptr);

//  enif_release_resource(ptr);
enif_keep_resource(ptr);
  return term;
}


// @@FUNCTIONS@@
// -- Start generating from Target_8h.xml on {{2011,6,29},{23,3,15}}--

static ERL_NIF_TERM LLVMInitializeNativeTarget_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeNativeTarget\r\n");
  LLVMBool retVal = LLVMInitializeNativeTarget();

  return   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false");
}

// --- Stop generating from Target_8h.xml

// -- Start generating from Scalar_8h.xml on {{2011,6,29},{23,3,15}}--

static ERL_NIF_TERM LLVMAddCFGSimplificationPass_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAddCFGSimplificationPass\r\n");
  LLVMPassManagerRef PM;
  llvm_ptr_deref(env, argv[0], (void **) &PM);

LLVMAddCFGSimplificationPass(PM);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMAddGVNPass_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAddGVNPass\r\n");
  LLVMPassManagerRef PM;
  llvm_ptr_deref(env, argv[0], (void **) &PM);

LLVMAddGVNPass(PM);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMAddInstructionCombiningPass_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAddInstructionCombiningPass\r\n");
  LLVMPassManagerRef PM;
  llvm_ptr_deref(env, argv[0], (void **) &PM);

LLVMAddInstructionCombiningPass(PM);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMAddReassociatePass_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAddReassociatePass\r\n");
  LLVMPassManagerRef PM;
  llvm_ptr_deref(env, argv[0], (void **) &PM);

LLVMAddReassociatePass(PM);

  return enif_make_atom(env,"ok");
}

// --- Stop generating from Scalar_8h.xml

// -- Start generating from Initialization_8h.xml on {{2011,6,29},{23,3,14}}--

static ERL_NIF_TERM LLVMInitializeScalarOpts_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeScalarOpts\r\n");
  LLVMPassRegistryRef R;
  llvm_ptr_deref(env, argv[0], (void **) &R);

LLVMInitializeScalarOpts(R);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMInitializeInstCombine_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeInstCombine\r\n");
  LLVMPassRegistryRef R;
  llvm_ptr_deref(env, argv[0], (void **) &R);

LLVMInitializeInstCombine(R);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMInitializeInstrumentation_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeInstrumentation\r\n");
  LLVMPassRegistryRef R;
  llvm_ptr_deref(env, argv[0], (void **) &R);

LLVMInitializeInstrumentation(R);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMInitializeIPA_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeIPA\r\n");
  LLVMPassRegistryRef R;
  llvm_ptr_deref(env, argv[0], (void **) &R);

LLVMInitializeIPA(R);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMInitializeCodeGen_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeCodeGen\r\n");
  LLVMPassRegistryRef R;
  llvm_ptr_deref(env, argv[0], (void **) &R);

LLVMInitializeCodeGen(R);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMInitializeTarget_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeTarget\r\n");
  LLVMPassRegistryRef R;
  llvm_ptr_deref(env, argv[0], (void **) &R);

LLVMInitializeTarget(R);

  return enif_make_atom(env,"ok");
}

// --- Stop generating from Initialization_8h.xml

// -- Start generating from IPO_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from IPO_8h.xml

// -- Start generating from ExecutionEngine_8h.xml on {{2011,6,29},{23,3,14}}--

static ERL_NIF_TERM LLVMLinkInInterpreter_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMLinkInInterpreter\r\n");
LLVMLinkInInterpreter();

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMCreateGenericValueOfFloat_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMCreateGenericValueOfFloat\r\n");
  LLVMTypeRef Ty;
  llvm_ptr_deref(env, argv[0], (void **) &Ty);

  double N;
  enif_get_double(env, argv[1], (double*)&N);

  LLVMGenericValueRef retVal = LLVMCreateGenericValueOfFloat(Ty,N);

  return   llvm_ptr_create(env, RTLLVMGenericValueRef, retVal);
}

static ERL_NIF_TERM LLVMGenericValueToFloat_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGenericValueToFloat\r\n");
  LLVMTypeRef TyRef;
  llvm_ptr_deref(env, argv[0], (void **) &TyRef);

  LLVMGenericValueRef GenVal;
  llvm_ptr_deref(env, argv[1], (void **) &GenVal);

  double retVal = LLVMGenericValueToFloat(TyRef,GenVal);

  return   enif_make_double(env,retVal);
}

static ERL_NIF_TERM LLVMCreateExecutionEngineForModule_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMCreateExecutionEngineForModule\r\n");
  LLVMExecutionEngineRef * OutEE = (LLVMExecutionEngineRef *)calloc(1,sizeof(LLVMExecutionEngineRef *));

  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

  char ** OutError = (char **)calloc(1,sizeof(char **));

  LLVMBool retVal = LLVMCreateExecutionEngineForModule(OutEE,M,OutError);

  return   enif_make_tuple3(env,   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false"),llvm_ptr_create(env, RTLLVMExecutionEngineRef,*OutEE),*OutError != NULL?enif_make_string(env, *OutError,ERL_NIF_LATIN1):enif_make_list(env,0));

;
}

static ERL_NIF_TERM LLVMCreateInterpreterForModule_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMCreateInterpreterForModule\r\n");
  LLVMExecutionEngineRef * OutInterp = (LLVMExecutionEngineRef *)calloc(1,sizeof(LLVMExecutionEngineRef *));

  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

  char ** OutError = (char **)calloc(1,sizeof(char **));

  LLVMBool retVal = LLVMCreateInterpreterForModule(OutInterp,M,OutError);

  return   enif_make_tuple3(env,   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false"),llvm_ptr_create(env, RTLLVMExecutionEngineRef,*OutInterp),*OutError != NULL?enif_make_string(env, *OutError,ERL_NIF_LATIN1):enif_make_list(env,0));

;
}

static ERL_NIF_TERM LLVMCreateJITCompilerForModule_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMCreateJITCompilerForModule\r\n");
  LLVMExecutionEngineRef * OutJIT = (LLVMExecutionEngineRef *)calloc(1,sizeof(LLVMExecutionEngineRef *));

  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

  unsigned OptLevel;
  enif_get_uint(env, argv[1], (unsigned*)&OptLevel);

  char ** OutError = (char **)calloc(1,sizeof(char **));

  LLVMBool retVal = LLVMCreateJITCompilerForModule(OutJIT,M,OptLevel,OutError);

  return   enif_make_tuple3(env,   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false"),llvm_ptr_create(env, RTLLVMExecutionEngineRef,*OutJIT),*OutError != NULL?enif_make_string(env, *OutError,ERL_NIF_LATIN1):enif_make_list(env,0));

;
}

static ERL_NIF_TERM LLVMRunFunction_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMRunFunction\r\n");
  LLVMExecutionEngineRef EE;
  llvm_ptr_deref(env, argv[0], (void **) &EE);

  LLVMValueRef F;
  llvm_ptr_deref(env, argv[1], (void **) &F);

  unsigned NumArgs;
  enif_get_uint(env, argv[2], (unsigned*)&NumArgs);

  int Argssize = 0;
  ERL_NIF_TERM *Argsarray;
  enif_get_tuple(env, argv[3], &Argssize, (const ERL_NIF_TERM **)&Argsarray);
  LLVMGenericValueRef * Args;
  if (Argssize == 0)
    Args = NULL;
  else {
    Args = (LLVMGenericValueRef *)malloc(sizeof(LLVMGenericValueRef *)*Argssize);
    int i,local_size=0;
    ERL_NIF_TERM *local_array;
    for(i = 0;i < Argssize; i++) {
      enif_get_tuple(env,*(Argsarray+i), &local_size, (const ERL_NIF_TERM **)&local_array);
      llvm_ptr_deref(env,*(local_array+1),(void **)Args+i);
    }
  }

  LLVMGenericValueRef retVal = LLVMRunFunction(EE,F,NumArgs,Args);

  return   llvm_ptr_create(env, RTLLVMGenericValueRef, retVal);
}

// --- Stop generating from ExecutionEngine_8h.xml

// -- Start generating from Core_8h.xml on {{2011,6,29},{23,3,14}}--

static ERL_NIF_TERM LLVMGetGlobalContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetGlobalContext\r\n");
  LLVMContextRef retVal = LLVMGetGlobalContext();

  return   llvm_ptr_create(env, RTLLVMContextRef, retVal);
}

static ERL_NIF_TERM LLVMModuleCreateWithName_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMModuleCreateWithName\r\n");
  const char *ModuleID = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[0], (char*)ModuleID, 255, ERL_NIF_LATIN1);

  LLVMModuleRef retVal = LLVMModuleCreateWithName(ModuleID);

  return   llvm_ptr_create(env, RTLLVMModuleRef, retVal);
}

static ERL_NIF_TERM LLVMDumpModule_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMDumpModule\r\n");
  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

LLVMDumpModule(M);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMInt1TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt1TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMInt1TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt8TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt8TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMInt8TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt16TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt16TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMInt16TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt32TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt32TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMInt32TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt64TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt64TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMInt64TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMIntTypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMIntTypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  unsigned NumBits;
  enif_get_uint(env, argv[1], (unsigned*)&NumBits);

  LLVMTypeRef retVal = LLVMIntTypeInContext(C,NumBits);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt1Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt1Type\r\n");
  LLVMTypeRef retVal = LLVMInt1Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt8Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt8Type\r\n");
  LLVMTypeRef retVal = LLVMInt8Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt16Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt16Type\r\n");
  LLVMTypeRef retVal = LLVMInt16Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt32Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt32Type\r\n");
  LLVMTypeRef retVal = LLVMInt32Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMInt64Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInt64Type\r\n");
  LLVMTypeRef retVal = LLVMInt64Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMIntType_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMIntType\r\n");
  unsigned NumBits;
  enif_get_uint(env, argv[0], (unsigned*)&NumBits);

  LLVMTypeRef retVal = LLVMIntType(NumBits);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMFloatTypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMFloatTypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMFloatTypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMDoubleTypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMDoubleTypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMDoubleTypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMFP128TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMFP128TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMFP128TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMPPCFP128TypeInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMPPCFP128TypeInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMTypeRef retVal = LLVMPPCFP128TypeInContext(C);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMFloatType_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMFloatType\r\n");
  LLVMTypeRef retVal = LLVMFloatType();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMDoubleType_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMDoubleType\r\n");
  LLVMTypeRef retVal = LLVMDoubleType();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMFP128Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMFP128Type\r\n");
  LLVMTypeRef retVal = LLVMFP128Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMPPCFP128Type_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMPPCFP128Type\r\n");
  LLVMTypeRef retVal = LLVMPPCFP128Type();

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMFunctionType_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMFunctionType\r\n");
  LLVMTypeRef ReturnType;
  llvm_ptr_deref(env, argv[0], (void **) &ReturnType);

  int ParamTypessize = 0;
  ERL_NIF_TERM *ParamTypesarray;
  enif_get_tuple(env, argv[1], &ParamTypessize, (const ERL_NIF_TERM **)&ParamTypesarray);
  LLVMTypeRef * ParamTypes;
  if (ParamTypessize == 0)
    ParamTypes = NULL;
  else {
    ParamTypes = (LLVMTypeRef *)malloc(sizeof(LLVMTypeRef *)*ParamTypessize);
    int i,local_size=0;
    ERL_NIF_TERM *local_array;
    for(i = 0;i < ParamTypessize; i++) {
      enif_get_tuple(env,*(ParamTypesarray+i), &local_size, (const ERL_NIF_TERM **)&local_array);
      llvm_ptr_deref(env,*(local_array+1),(void **)ParamTypes+i);
    }
  }

  unsigned ParamCount;
  enif_get_uint(env, argv[2], (unsigned*)&ParamCount);

  char *IsVarArg_tmp = (char *) malloc(sizeof(char) * 255);
  enif_get_atom(env, argv[3], (char*)IsVarArg_tmp, 255, ERL_NIF_LATIN1);
  LLVMBool IsVarArg = (strcmp(IsVarArg_tmp,"true") == 0);

  LLVMTypeRef retVal = LLVMFunctionType(ReturnType,ParamTypes,ParamCount,IsVarArg);

  return   llvm_ptr_create(env, RTLLVMTypeRef, retVal);
}

static ERL_NIF_TERM LLVMDumpValue_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMDumpValue\r\n");
  LLVMValueRef Val;
  llvm_ptr_deref(env, argv[0], (void **) &Val);

LLVMDumpValue(Val);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMConstNull_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMConstNull\r\n");
  LLVMTypeRef Ty;
  llvm_ptr_deref(env, argv[0], (void **) &Ty);

  LLVMValueRef retVal = LLVMConstNull(Ty);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMConstReal_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMConstReal\r\n");
  LLVMTypeRef RealTy;
  llvm_ptr_deref(env, argv[0], (void **) &RealTy);

  double N;
  enif_get_double(env, argv[1], (double*)&N);

  LLVMValueRef retVal = LLVMConstReal(RealTy,N);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMGetLinkage_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetLinkage\r\n");
  LLVMValueRef Global;
  llvm_ptr_deref(env, argv[0], (void **) &Global);

  LLVMLinkage retVal = LLVMGetLinkage(Global);

  return   enif_make_int(env, (int)RTLLVMLinkage);
}

static ERL_NIF_TERM LLVMSetLinkage_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMSetLinkage\r\n");
  LLVMValueRef Global;
  llvm_ptr_deref(env, argv[0], (void **) &Global);

  LLVMLinkage Linkage;
  enif_get_uint(env, argv[1], (LLVMLinkage*)&Linkage);

LLVMSetLinkage(Global,Linkage);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMAddFunction_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAddFunction\r\n");
  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[1], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMTypeRef FunctionTy;
  llvm_ptr_deref(env, argv[2], (void **) &FunctionTy);

  LLVMValueRef retVal = LLVMAddFunction(M,Name,FunctionTy);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMGetNamedFunction_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetNamedFunction\r\n");
  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[1], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMGetNamedFunction(M,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMGetParam_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetParam\r\n");
  LLVMValueRef Fn;
  llvm_ptr_deref(env, argv[0], (void **) &Fn);

  unsigned Index;
  enif_get_uint(env, argv[1], (unsigned*)&Index);

  LLVMValueRef retVal = LLVMGetParam(Fn,Index);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMGetBasicBlockParent_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetBasicBlockParent\r\n");
  LLVMBasicBlockRef BB;
  llvm_ptr_deref(env, argv[0], (void **) &BB);

  LLVMValueRef retVal = LLVMGetBasicBlockParent(BB);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMAppendBasicBlock_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAppendBasicBlock\r\n");
  LLVMValueRef Fn;
  llvm_ptr_deref(env, argv[0], (void **) &Fn);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[1], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMBasicBlockRef retVal = LLVMAppendBasicBlock(Fn,Name);

  return   llvm_ptr_create(env, RTLLVMBasicBlockRef, retVal);
}

static ERL_NIF_TERM LLVMAddIncoming_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMAddIncoming\r\n");
  LLVMValueRef PhiNode;
  llvm_ptr_deref(env, argv[0], (void **) &PhiNode);

  int IncomingValuessize = 0;
  ERL_NIF_TERM *IncomingValuesarray;
  enif_get_tuple(env, argv[1], &IncomingValuessize, (const ERL_NIF_TERM **)&IncomingValuesarray);
  LLVMValueRef * IncomingValues;
  if (IncomingValuessize == 0)
    IncomingValues = NULL;
  else {
    IncomingValues = (LLVMValueRef *)malloc(sizeof(LLVMValueRef *)*IncomingValuessize);
    int i,local_size=0;
    ERL_NIF_TERM *local_array;
    for(i = 0;i < IncomingValuessize; i++) {
      enif_get_tuple(env,*(IncomingValuesarray+i), &local_size, (const ERL_NIF_TERM **)&local_array);
      llvm_ptr_deref(env,*(local_array+1),(void **)IncomingValues+i);
    }
  }

  int IncomingBlockssize = 0;
  ERL_NIF_TERM *IncomingBlocksarray;
  enif_get_tuple(env, argv[2], &IncomingBlockssize, (const ERL_NIF_TERM **)&IncomingBlocksarray);
  LLVMBasicBlockRef * IncomingBlocks;
  if (IncomingBlockssize == 0)
    IncomingBlocks = NULL;
  else {
    IncomingBlocks = (LLVMBasicBlockRef *)malloc(sizeof(LLVMBasicBlockRef *)*IncomingBlockssize);
    int i,local_size=0;
    ERL_NIF_TERM *local_array;
    for(i = 0;i < IncomingBlockssize; i++) {
      enif_get_tuple(env,*(IncomingBlocksarray+i), &local_size, (const ERL_NIF_TERM **)&local_array);
      llvm_ptr_deref(env,*(local_array+1),(void **)IncomingBlocks+i);
    }
  }

  unsigned Count;
  enif_get_uint(env, argv[3], (unsigned*)&Count);

LLVMAddIncoming(PhiNode,IncomingValues,IncomingBlocks,Count);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMCreateBuilderInContext_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMCreateBuilderInContext\r\n");
  LLVMContextRef C;
  llvm_ptr_deref(env, argv[0], (void **) &C);

  LLVMBuilderRef retVal = LLVMCreateBuilderInContext(C);

  return   llvm_ptr_create(env, RTLLVMBuilderRef, retVal);
}

static ERL_NIF_TERM LLVMPositionBuilderAtEnd_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMPositionBuilderAtEnd\r\n");
  LLVMBuilderRef Builder;
  llvm_ptr_deref(env, argv[0], (void **) &Builder);

  LLVMBasicBlockRef Block;
  llvm_ptr_deref(env, argv[1], (void **) &Block);

LLVMPositionBuilderAtEnd(Builder,Block);

  return enif_make_atom(env,"ok");
}

static ERL_NIF_TERM LLVMGetInsertBlock_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetInsertBlock\r\n");
  LLVMBuilderRef Builder;
  llvm_ptr_deref(env, argv[0], (void **) &Builder);

  LLVMBasicBlockRef retVal = LLVMGetInsertBlock(Builder);

  return   llvm_ptr_create(env, RTLLVMBasicBlockRef, retVal);
}

static ERL_NIF_TERM LLVMBuildRet_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildRet\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef V;
  llvm_ptr_deref(env, argv[1], (void **) &V);

  LLVMValueRef retVal = LLVMBuildRet(B,V);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildBr_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildBr\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMBasicBlockRef Dest;
  llvm_ptr_deref(env, argv[1], (void **) &Dest);

  LLVMValueRef retVal = LLVMBuildBr(B,Dest);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildCondBr_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildCondBr\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef If;
  llvm_ptr_deref(env, argv[1], (void **) &If);

  LLVMBasicBlockRef Then;
  llvm_ptr_deref(env, argv[2], (void **) &Then);

  LLVMBasicBlockRef Else;
  llvm_ptr_deref(env, argv[3], (void **) &Else);

  LLVMValueRef retVal = LLVMBuildCondBr(B,If,Then,Else);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildFAdd_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildFAdd\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef LHS;
  llvm_ptr_deref(env, argv[1], (void **) &LHS);

  LLVMValueRef RHS;
  llvm_ptr_deref(env, argv[2], (void **) &RHS);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[3], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildFAdd(B,LHS,RHS,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildFSub_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildFSub\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef LHS;
  llvm_ptr_deref(env, argv[1], (void **) &LHS);

  LLVMValueRef RHS;
  llvm_ptr_deref(env, argv[2], (void **) &RHS);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[3], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildFSub(B,LHS,RHS,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildFMul_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildFMul\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef LHS;
  llvm_ptr_deref(env, argv[1], (void **) &LHS);

  LLVMValueRef RHS;
  llvm_ptr_deref(env, argv[2], (void **) &RHS);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[3], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildFMul(B,LHS,RHS,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildUIToFP_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildUIToFP\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef Val;
  llvm_ptr_deref(env, argv[1], (void **) &Val);

  LLVMTypeRef DestTy;
  llvm_ptr_deref(env, argv[2], (void **) &DestTy);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[3], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildUIToFP(B,Val,DestTy,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildFCmp_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildFCmp\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMRealPredicate Op;
  enif_get_uint(env, argv[1], (LLVMRealPredicate*)&Op);

  LLVMValueRef LHS;
  llvm_ptr_deref(env, argv[2], (void **) &LHS);

  LLVMValueRef RHS;
  llvm_ptr_deref(env, argv[3], (void **) &RHS);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[4], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildFCmp(B,Op,LHS,RHS,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildPhi_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildPhi\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMTypeRef Ty;
  llvm_ptr_deref(env, argv[1], (void **) &Ty);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[2], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildPhi(B,Ty,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMBuildCall_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMBuildCall\r\n");
  LLVMBuilderRef B;
  llvm_ptr_deref(env, argv[0], (void **) &B);

  LLVMValueRef Fn;
  llvm_ptr_deref(env, argv[1], (void **) &Fn);

  int Argssize = 0;
  ERL_NIF_TERM *Argsarray;
  enif_get_tuple(env, argv[2], &Argssize, (const ERL_NIF_TERM **)&Argsarray);
  LLVMValueRef * Args;
  if (Argssize == 0)
    Args = NULL;
  else {
    Args = (LLVMValueRef *)malloc(sizeof(LLVMValueRef *)*Argssize);
    int i,local_size=0;
    ERL_NIF_TERM *local_array;
    for(i = 0;i < Argssize; i++) {
      enif_get_tuple(env,*(Argsarray+i), &local_size, (const ERL_NIF_TERM **)&local_array);
      llvm_ptr_deref(env,*(local_array+1),(void **)Args+i);
    }
  }

  unsigned NumArgs;
  enif_get_uint(env, argv[3], (unsigned*)&NumArgs);

  const char *Name = (char *) malloc(sizeof(char) * 255);
  enif_get_string(env, argv[4], (char*)Name, 255, ERL_NIF_LATIN1);

  LLVMValueRef retVal = LLVMBuildCall(B,Fn,Args,NumArgs,Name);

  return   llvm_ptr_create(env, RTLLVMValueRef, retVal);
}

static ERL_NIF_TERM LLVMGetGlobalPassRegistry_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMGetGlobalPassRegistry\r\n");
  LLVMPassRegistryRef retVal = LLVMGetGlobalPassRegistry();

  return   llvm_ptr_create(env, RTLLVMPassRegistryRef, retVal);
}

static ERL_NIF_TERM LLVMCreateFunctionPassManagerForModule_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMCreateFunctionPassManagerForModule\r\n");
  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[0], (void **) &M);

  LLVMPassManagerRef retVal = LLVMCreateFunctionPassManagerForModule(M);

  return   llvm_ptr_create(env, RTLLVMPassManagerRef, retVal);
}

static ERL_NIF_TERM LLVMRunPassManager_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMRunPassManager\r\n");
  LLVMPassManagerRef PM;
  llvm_ptr_deref(env, argv[0], (void **) &PM);

  LLVMModuleRef M;
  llvm_ptr_deref(env, argv[1], (void **) &M);

  LLVMBool retVal = LLVMRunPassManager(PM,M);

  return   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false");
}

static ERL_NIF_TERM LLVMInitializeFunctionPassManager_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMInitializeFunctionPassManager\r\n");
  LLVMPassManagerRef FPM;
  llvm_ptr_deref(env, argv[0], (void **) &FPM);

  LLVMBool retVal = LLVMInitializeFunctionPassManager(FPM);

  return   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false");
}

static ERL_NIF_TERM LLVMRunFunctionPassManager_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMRunFunctionPassManager\r\n");
  LLVMPassManagerRef FPM;
  llvm_ptr_deref(env, argv[0], (void **) &FPM);

  LLVMValueRef F;
  llvm_ptr_deref(env, argv[1], (void **) &F);

  LLVMBool retVal = LLVMRunFunctionPassManager(FPM,F);

  return   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false");
}

static ERL_NIF_TERM LLVMFinalizeFunctionPassManager_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  printf("\rCalling LLVMFinalizeFunctionPassManager\r\n");
  LLVMPassManagerRef FPM;
  llvm_ptr_deref(env, argv[0], (void **) &FPM);

  LLVMBool retVal = LLVMFinalizeFunctionPassManager(FPM);

  return   retVal ? enif_make_atom(env,"true") : enif_make_atom(env,"false");
}

// --- Stop generating from Core_8h.xml


static ErlNifFunc nif_funcs[] =
  {
// @@NIF_MAPPINGS@@
// -- Start generating from Target_8h.xml on {{2011,6,29},{23,3,15}}--

    {"LLVMInitializeNativeTarget_internal",0,LLVMInitializeNativeTarget_nif},
// --- Stop generating from Target_8h.xml

// -- Start generating from Scalar_8h.xml on {{2011,6,29},{23,3,15}}--

    {"LLVMAddCFGSimplificationPass_internal",1,LLVMAddCFGSimplificationPass_nif},
    {"LLVMAddGVNPass_internal",1,LLVMAddGVNPass_nif},
    {"LLVMAddInstructionCombiningPass_internal",1,LLVMAddInstructionCombiningPass_nif},
    {"LLVMAddReassociatePass_internal",1,LLVMAddReassociatePass_nif},
// --- Stop generating from Scalar_8h.xml

// -- Start generating from Initialization_8h.xml on {{2011,6,29},{23,3,14}}--

    {"LLVMInitializeScalarOpts_internal",1,LLVMInitializeScalarOpts_nif},
    {"LLVMInitializeInstCombine_internal",1,LLVMInitializeInstCombine_nif},
    {"LLVMInitializeInstrumentation_internal",1,LLVMInitializeInstrumentation_nif},
    {"LLVMInitializeIPA_internal",1,LLVMInitializeIPA_nif},
    {"LLVMInitializeCodeGen_internal",1,LLVMInitializeCodeGen_nif},
    {"LLVMInitializeTarget_internal",1,LLVMInitializeTarget_nif},
// --- Stop generating from Initialization_8h.xml

// -- Start generating from IPO_8h.xml on {{2011,6,29},{23,3,14}}--

// --- Stop generating from IPO_8h.xml

// -- Start generating from ExecutionEngine_8h.xml on {{2011,6,29},{23,3,14}}--

    {"LLVMLinkInInterpreter_internal",0,LLVMLinkInInterpreter_nif},
    {"LLVMCreateGenericValueOfFloat_internal",2,LLVMCreateGenericValueOfFloat_nif},
    {"LLVMGenericValueToFloat_internal",2,LLVMGenericValueToFloat_nif},
    {"LLVMCreateExecutionEngineForModule_internal",1,LLVMCreateExecutionEngineForModule_nif},
    {"LLVMCreateInterpreterForModule_internal",1,LLVMCreateInterpreterForModule_nif},
    {"LLVMCreateJITCompilerForModule_internal",2,LLVMCreateJITCompilerForModule_nif},
    {"LLVMRunFunction_internal",4,LLVMRunFunction_nif},
// --- Stop generating from ExecutionEngine_8h.xml

// -- Start generating from Core_8h.xml on {{2011,6,29},{23,3,14}}--

    {"LLVMGetGlobalContext_internal",0,LLVMGetGlobalContext_nif},
    {"LLVMModuleCreateWithName_internal",1,LLVMModuleCreateWithName_nif},
    {"LLVMDumpModule_internal",1,LLVMDumpModule_nif},
    {"LLVMInt1TypeInContext_internal",1,LLVMInt1TypeInContext_nif},
    {"LLVMInt8TypeInContext_internal",1,LLVMInt8TypeInContext_nif},
    {"LLVMInt16TypeInContext_internal",1,LLVMInt16TypeInContext_nif},
    {"LLVMInt32TypeInContext_internal",1,LLVMInt32TypeInContext_nif},
    {"LLVMInt64TypeInContext_internal",1,LLVMInt64TypeInContext_nif},
    {"LLVMIntTypeInContext_internal",2,LLVMIntTypeInContext_nif},
    {"LLVMInt1Type_internal",0,LLVMInt1Type_nif},
    {"LLVMInt8Type_internal",0,LLVMInt8Type_nif},
    {"LLVMInt16Type_internal",0,LLVMInt16Type_nif},
    {"LLVMInt32Type_internal",0,LLVMInt32Type_nif},
    {"LLVMInt64Type_internal",0,LLVMInt64Type_nif},
    {"LLVMIntType_internal",1,LLVMIntType_nif},
    {"LLVMFloatTypeInContext_internal",1,LLVMFloatTypeInContext_nif},
    {"LLVMDoubleTypeInContext_internal",1,LLVMDoubleTypeInContext_nif},
    {"LLVMFP128TypeInContext_internal",1,LLVMFP128TypeInContext_nif},
    {"LLVMPPCFP128TypeInContext_internal",1,LLVMPPCFP128TypeInContext_nif},
    {"LLVMFloatType_internal",0,LLVMFloatType_nif},
    {"LLVMDoubleType_internal",0,LLVMDoubleType_nif},
    {"LLVMFP128Type_internal",0,LLVMFP128Type_nif},
    {"LLVMPPCFP128Type_internal",0,LLVMPPCFP128Type_nif},
    {"LLVMFunctionType_internal",4,LLVMFunctionType_nif},
    {"LLVMDumpValue_internal",1,LLVMDumpValue_nif},
    {"LLVMConstNull_internal",1,LLVMConstNull_nif},
    {"LLVMConstReal_internal",2,LLVMConstReal_nif},
    {"LLVMGetLinkage_internal",1,LLVMGetLinkage_nif},
    {"LLVMSetLinkage_internal",2,LLVMSetLinkage_nif},
    {"LLVMAddFunction_internal",3,LLVMAddFunction_nif},
    {"LLVMGetNamedFunction_internal",2,LLVMGetNamedFunction_nif},
    {"LLVMGetParam_internal",2,LLVMGetParam_nif},
    {"LLVMGetBasicBlockParent_internal",1,LLVMGetBasicBlockParent_nif},
    {"LLVMAppendBasicBlock_internal",2,LLVMAppendBasicBlock_nif},
    {"LLVMAddIncoming_internal",4,LLVMAddIncoming_nif},
    {"LLVMCreateBuilderInContext_internal",1,LLVMCreateBuilderInContext_nif},
    {"LLVMPositionBuilderAtEnd_internal",2,LLVMPositionBuilderAtEnd_nif},
    {"LLVMGetInsertBlock_internal",1,LLVMGetInsertBlock_nif},
    {"LLVMBuildRet_internal",2,LLVMBuildRet_nif},
    {"LLVMBuildBr_internal",2,LLVMBuildBr_nif},
    {"LLVMBuildCondBr_internal",4,LLVMBuildCondBr_nif},
    {"LLVMBuildFAdd_internal",4,LLVMBuildFAdd_nif},
    {"LLVMBuildFSub_internal",4,LLVMBuildFSub_nif},
    {"LLVMBuildFMul_internal",4,LLVMBuildFMul_nif},
    {"LLVMBuildUIToFP_internal",4,LLVMBuildUIToFP_nif},
    {"LLVMBuildFCmp_internal",5,LLVMBuildFCmp_nif},
    {"LLVMBuildPhi_internal",3,LLVMBuildPhi_nif},
    {"LLVMBuildCall_internal",5,LLVMBuildCall_nif},
    {"LLVMGetGlobalPassRegistry_internal",0,LLVMGetGlobalPassRegistry_nif},
    {"LLVMCreateFunctionPassManagerForModule_internal",1,LLVMCreateFunctionPassManagerForModule_nif},
    {"LLVMRunPassManager_internal",2,LLVMRunPassManager_nif},
    {"LLVMInitializeFunctionPassManager_internal",1,LLVMInitializeFunctionPassManager_nif},
    {"LLVMRunFunctionPassManager_internal",2,LLVMRunFunctionPassManager_nif},
    {"LLVMFinalizeFunctionPassManager_internal",1,LLVMFinalizeFunctionPassManager_nif},
// --- Stop generating from Core_8h.xml

  };

ERL_NIF_INIT(llevm,nif_funcs,load_nif,NULL,NULL,NULL)
