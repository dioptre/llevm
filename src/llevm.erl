-module(llevm).

-include("llevm.hrl").

-on_load(load_my_nifs/0).

%% -- Start generating from Core_8h.xml on {{2011,6,19},{21,9,49}}--

-export(['LLVMGetGlobalContext'/0]).
-export(['LLVMModuleCreateWithName'/1]).
-export(['LLVMDumpModule'/1]).
-export(['LLVMDoubleType'/0]).
-export(['LLVMFunctionType'/4]).
-export(['LLVMDumpValue'/1]).
-export(['LLVMConstReal'/2]).
-export(['LLVMGetLinkage'/1]).
-export(['LLVMSetLinkage'/2]).
-export(['LLVMAddFunction'/3]).
-export(['LLVMGetNamedFunction'/2]).
-export(['LLVMGetParam'/2]).
-export(['LLVMAppendBasicBlock'/2]).
-export(['LLVMCreateBuilderInContext'/1]).
-export(['LLVMPositionBuilderAtEnd'/2]).
-export(['LLVMBuildRet'/2]).
-export(['LLVMBuildFAdd'/4]).
-export(['LLVMBuildFSub'/4]).
-export(['LLVMBuildFMul'/4]).
-export(['LLVMBuildUIToFP'/4]).
-export(['LLVMBuildFCmp'/5]).
-export(['LLVMBuildCall'/5]).
%% --- Stop generating from Core_8h.xml


-type llvm_ptr(Base) :: {llvm_ptr, Base}.

%% -- Start generating from Core_8h.xml on {{2011,6,19},{21,9,49}}--

-opaque 'LLVMAttribute'() :: {'LLVMAttribute',integer()}.
-opaque 'LLVMOpcode'() :: {'LLVMOpcode',integer()}.
-opaque 'LLVMTypeKind'() :: {'LLVMTypeKind',integer()}.
-opaque 'LLVMLinkage'() :: {'LLVMLinkage',integer()}.
-opaque 'LLVMVisibility'() :: {'LLVMVisibility',integer()}.
-opaque 'LLVMCallConv'() :: {'LLVMCallConv',integer()}.
-opaque 'LLVMIntPredicate'() :: {'LLVMIntPredicate',integer()}.
-opaque 'LLVMRealPredicate'() :: {'LLVMRealPredicate',integer()}.
-type 'LLVMBool'() :: integer().
%% 

-opaque 'LLVMContextRef'() :: {'LLVMContextRef',binary()}.
%% The top-level container for all LLVM global data. See the LLVMContext class. 
-opaque 'LLVMModuleRef'() :: {'LLVMModuleRef',binary()}.
%% The top-level container for all other LLVM Intermediate Representation (IR) objects. See the llvm::Module class. 
-opaque 'LLVMTypeRef'() :: {'LLVMTypeRef',binary()}.
%% Each value in the LLVM IR has a type, an LLVMTypeRef. See the llvm::Type class. 
-opaque 'LLVMTypeHandleRef'() :: {'LLVMTypeHandleRef',binary()}.
%% When building recursive types using LLVMRefineType, LLVMTypeRef values may become invalid; use LLVMTypeHandleRef to resolve this problem. See the llvm::AbstractTypeHolder class. 
-opaque 'LLVMValueRef'() :: {'LLVMValueRef',binary()}.
%% 
-opaque 'LLVMBasicBlockRef'() :: {'LLVMBasicBlockRef',binary()}.
%% 
-opaque 'LLVMBuilderRef'() :: {'LLVMBuilderRef',binary()}.
%% 
-opaque 'LLVMModuleProviderRef'() :: {'LLVMModuleProviderRef',binary()}.
%% 
-opaque 'LLVMMemoryBufferRef'() :: {'LLVMMemoryBufferRef',binary()}.
%% 
-opaque 'LLVMPassManagerRef'() :: {'LLVMPassManagerRef',binary()}.
%% See the llvm::PassManagerBase class. 
-opaque 'LLVMPassRegistryRef'() :: {'LLVMPassRegistryRef',binary()}.
%% See the llvm::PassRegistry class. 
-opaque 'LLVMUseRef'() :: {'LLVMUseRef',binary()}.
%% Used to get the users and usees of a Value. See the llvm::Use class. 
%% --- Stop generating from Core_8h.xml


load_my_nifs() ->
    erlang:load_nif(filename:join([code:priv_dir(llevm),"x86_64/llevm"]),0).

%% -- Start generating from Core_8h.xml on {{2011,6,19},{21,9,49}}--

%% @doc 
-spec 'LLVMGetGlobalContext'() -> 'LLVMContextRef'().
'LLVMGetGlobalContext'() ->
	{'LLVMContextRef','LLVMGetGlobalContext_internal'()}.
'LLVMGetGlobalContext_internal'() ->
	nif_not_loaded.

%% @doc See llvm::Module::Module. 
-spec 'LLVMModuleCreateWithName'(ModuleID :: string()) -> 'LLVMModuleRef'().
'LLVMModuleCreateWithName'(ModuleID) ->
	{'LLVMModuleRef','LLVMModuleCreateWithName_internal'(ModuleID)}.
'LLVMModuleCreateWithName_internal'(_ModuleID) ->
	nif_not_loaded.

%% @doc See Module::dump. 
-spec 'LLVMDumpModule'(M :: 'LLVMModuleRef'()) -> atom().
'LLVMDumpModule'({'LLVMModuleRef',M}) ->
	{atom,'LLVMDumpModule_internal'(M)}.
'LLVMDumpModule_internal'(_M) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMDoubleType'() -> 'LLVMTypeRef'().
'LLVMDoubleType'() ->
	{'LLVMTypeRef','LLVMDoubleType_internal'()}.
'LLVMDoubleType_internal'() ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMFunctionType'(ReturnType :: 'LLVMTypeRef'(),ParamTypes :: tuple('LLVMTypeRef'()),ParamCount :: integer(),IsVarArg :: boolean()) -> 'LLVMTypeRef'().
'LLVMFunctionType'({'LLVMTypeRef',ReturnType},ParamTypes,ParamCount,IsVarArg) ->
	{'LLVMTypeRef','LLVMFunctionType_internal'(ReturnType,ParamTypes,ParamCount,IsVarArg)}.
'LLVMFunctionType_internal'(_ReturnType,_ParamTypes,_ParamCount,_IsVarArg) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMDumpValue'(Val :: 'LLVMValueRef'()) -> atom().
'LLVMDumpValue'({'LLVMValueRef',Val}) ->
	{atom,'LLVMDumpValue_internal'(Val)}.
'LLVMDumpValue_internal'(_Val) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMConstReal'(RealTy :: 'LLVMTypeRef'(),N :: float()) -> 'LLVMValueRef'().
'LLVMConstReal'({'LLVMTypeRef',RealTy},N) ->
	{'LLVMValueRef','LLVMConstReal_internal'(RealTy,N)}.
'LLVMConstReal_internal'(_RealTy,_N) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMGetLinkage'(Global :: 'LLVMValueRef'()) -> 'LLVMLinkage'().
'LLVMGetLinkage'({'LLVMValueRef',Global}) ->
	{'LLVMLinkage','LLVMGetLinkage_internal'(Global)}.
'LLVMGetLinkage_internal'(_Global) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMSetLinkage'(Global :: 'LLVMValueRef'(),Linkage :: 'LLVMLinkage'()) -> atom().
'LLVMSetLinkage'({'LLVMValueRef',Global},{'LLVMLinkage',Linkage}) ->
	{atom,'LLVMSetLinkage_internal'(Global,Linkage)}.
'LLVMSetLinkage_internal'(_Global,_Linkage) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMAddFunction'(M :: 'LLVMModuleRef'(),Name :: string(),FunctionTy :: 'LLVMTypeRef'()) -> 'LLVMValueRef'().
'LLVMAddFunction'({'LLVMModuleRef',M},Name,{'LLVMTypeRef',FunctionTy}) ->
	{'LLVMValueRef','LLVMAddFunction_internal'(M,Name,FunctionTy)}.
'LLVMAddFunction_internal'(_M,_Name,_FunctionTy) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMGetNamedFunction'(M :: 'LLVMModuleRef'(),Name :: string()) -> 'LLVMValueRef'().
'LLVMGetNamedFunction'({'LLVMModuleRef',M},Name) ->
	{'LLVMValueRef','LLVMGetNamedFunction_internal'(M,Name)}.
'LLVMGetNamedFunction_internal'(_M,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMGetParam'(Fn :: 'LLVMValueRef'(),Index :: integer()) -> 'LLVMValueRef'().
'LLVMGetParam'({'LLVMValueRef',Fn},Index) ->
	{'LLVMValueRef','LLVMGetParam_internal'(Fn,Index)}.
'LLVMGetParam_internal'(_Fn,_Index) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMAppendBasicBlock'(Fn :: 'LLVMValueRef'(),Name :: string()) -> 'LLVMBasicBlockRef'().
'LLVMAppendBasicBlock'({'LLVMValueRef',Fn},Name) ->
	{'LLVMBasicBlockRef','LLVMAppendBasicBlock_internal'(Fn,Name)}.
'LLVMAppendBasicBlock_internal'(_Fn,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMCreateBuilderInContext'(C :: 'LLVMContextRef'()) -> 'LLVMBuilderRef'().
'LLVMCreateBuilderInContext'({'LLVMContextRef',C}) ->
	{'LLVMBuilderRef','LLVMCreateBuilderInContext_internal'(C)}.
'LLVMCreateBuilderInContext_internal'(_C) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMPositionBuilderAtEnd'(Builder :: 'LLVMBuilderRef'(),Block :: 'LLVMBasicBlockRef'()) -> atom().
'LLVMPositionBuilderAtEnd'({'LLVMBuilderRef',Builder},{'LLVMBasicBlockRef',Block}) ->
	{atom,'LLVMPositionBuilderAtEnd_internal'(Builder,Block)}.
'LLVMPositionBuilderAtEnd_internal'(_Builder,_Block) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildRet'(B :: 'LLVMBuilderRef'(),V :: 'LLVMValueRef'()) -> 'LLVMValueRef'().
'LLVMBuildRet'({'LLVMBuilderRef',B},{'LLVMValueRef',V}) ->
	{'LLVMValueRef','LLVMBuildRet_internal'(B,V)}.
'LLVMBuildRet_internal'(_B,_V) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildFAdd'(B :: 'LLVMBuilderRef'(),LHS :: 'LLVMValueRef'(),RHS :: 'LLVMValueRef'(),Name :: string()) -> 'LLVMValueRef'().
'LLVMBuildFAdd'({'LLVMBuilderRef',B},{'LLVMValueRef',LHS},{'LLVMValueRef',RHS},Name) ->
	{'LLVMValueRef','LLVMBuildFAdd_internal'(B,LHS,RHS,Name)}.
'LLVMBuildFAdd_internal'(_B,_LHS,_RHS,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildFSub'(B :: 'LLVMBuilderRef'(),LHS :: 'LLVMValueRef'(),RHS :: 'LLVMValueRef'(),Name :: string()) -> 'LLVMValueRef'().
'LLVMBuildFSub'({'LLVMBuilderRef',B},{'LLVMValueRef',LHS},{'LLVMValueRef',RHS},Name) ->
	{'LLVMValueRef','LLVMBuildFSub_internal'(B,LHS,RHS,Name)}.
'LLVMBuildFSub_internal'(_B,_LHS,_RHS,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildFMul'(B :: 'LLVMBuilderRef'(),LHS :: 'LLVMValueRef'(),RHS :: 'LLVMValueRef'(),Name :: string()) -> 'LLVMValueRef'().
'LLVMBuildFMul'({'LLVMBuilderRef',B},{'LLVMValueRef',LHS},{'LLVMValueRef',RHS},Name) ->
	{'LLVMValueRef','LLVMBuildFMul_internal'(B,LHS,RHS,Name)}.
'LLVMBuildFMul_internal'(_B,_LHS,_RHS,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildUIToFP'(B :: 'LLVMBuilderRef'(),Val :: 'LLVMValueRef'(),DestTy :: 'LLVMTypeRef'(),Name :: string()) -> 'LLVMValueRef'().
'LLVMBuildUIToFP'({'LLVMBuilderRef',B},{'LLVMValueRef',Val},{'LLVMTypeRef',DestTy},Name) ->
	{'LLVMValueRef','LLVMBuildUIToFP_internal'(B,Val,DestTy,Name)}.
'LLVMBuildUIToFP_internal'(_B,_Val,_DestTy,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildFCmp'(B :: 'LLVMBuilderRef'(),Op :: 'LLVMRealPredicate'(),LHS :: 'LLVMValueRef'(),RHS :: 'LLVMValueRef'(),Name :: string()) -> 'LLVMValueRef'().
'LLVMBuildFCmp'({'LLVMBuilderRef',B},{'LLVMRealPredicate',Op},{'LLVMValueRef',LHS},{'LLVMValueRef',RHS},Name) ->
	{'LLVMValueRef','LLVMBuildFCmp_internal'(B,Op,LHS,RHS,Name)}.
'LLVMBuildFCmp_internal'(_B,_Op,_LHS,_RHS,_Name) ->
	nif_not_loaded.

%% @doc 
-spec 'LLVMBuildCall'(B :: 'LLVMBuilderRef'(),Fn :: 'LLVMValueRef'(),Args :: tuple('LLVMValueRef'()),NumArgs :: integer(),Name :: string()) -> 'LLVMValueRef'().
'LLVMBuildCall'({'LLVMBuilderRef',B},{'LLVMValueRef',Fn},Args,NumArgs,Name) ->
	{'LLVMValueRef','LLVMBuildCall_internal'(B,Fn,Args,NumArgs,Name)}.
'LLVMBuildCall_internal'(_B,_Fn,_Args,_NumArgs,_Name) ->
	nif_not_loaded.

%% --- Stop generating from Core_8h.xml

