##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=stack
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\msys\home\mcxiaoke\dsaac\ch3"
ProjectPath            := "E:\msys\home\mcxiaoke\dsaac\ch3\stack"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mcxiaoke
Date                   :=2012/7/4
CodeLitePath           :="E:\CodeLite"
LinkerName             :=gcc
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=gcc
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="E:\msys\home\mcxiaoke\dsaac\ch3\stack\stack.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
CmpOptions             := -g -O0 -Wall $(Preprocessors)
C_CmpOptions           := -g -O0 -Wall $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
LibPath                := $(LibraryPathSwitch). 


##
## User defined environment variables
##
CodeLiteDir:=E:\CodeLite
UNIT_TEST_PP_SRC_DIR:=E:\CodeLite\UnitTest++-1.3
Objects=$(IntermediateDirectory)/stack$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/stack$(ObjectSuffix): stack.c $(IntermediateDirectory)/stack$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "E:/msys/home/mcxiaoke/dsaac/ch3/stack/stack.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/stack$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stack$(DependSuffix): stack.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stack$(ObjectSuffix) -MF$(IntermediateDirectory)/stack$(DependSuffix) -MM "E:/msys/home/mcxiaoke/dsaac/ch3/stack/stack.c"

$(IntermediateDirectory)/stack$(PreprocessSuffix): stack.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stack$(PreprocessSuffix) "E:/msys/home/mcxiaoke/dsaac/ch3/stack/stack.c"

$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "E:/msys/home/mcxiaoke/dsaac/ch3/stack/main.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "E:/msys/home/mcxiaoke/dsaac/ch3/stack/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "E:/msys/home/mcxiaoke/dsaac/ch3/stack/main.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/stack$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/stack$(DependSuffix)
	$(RM) $(IntermediateDirectory)/stack$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "E:\msys\home\mcxiaoke\dsaac\ch3\.build-debug\stack"


