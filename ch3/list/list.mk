##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=list
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\msys\home\mcxiaoke\dsaac\ch3"
ProjectPath            := "E:\msys\home\mcxiaoke\dsaac\ch3\list"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mcxiaoke
Date                   :=2012/7/3
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
ObjectsFileList        :="E:\msys\home\mcxiaoke\dsaac\ch3\list\list.txt"
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
Objects=$(IntermediateDirectory)/list$(ObjectSuffix) 

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
$(IntermediateDirectory)/list$(ObjectSuffix): list.c $(IntermediateDirectory)/list$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "E:/msys/home/mcxiaoke/dsaac/ch3/list/list.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/list$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list$(DependSuffix): list.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list$(ObjectSuffix) -MF$(IntermediateDirectory)/list$(DependSuffix) -MM "E:/msys/home/mcxiaoke/dsaac/ch3/list/list.c"

$(IntermediateDirectory)/list$(PreprocessSuffix): list.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list$(PreprocessSuffix) "E:/msys/home/mcxiaoke/dsaac/ch3/list/list.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/list$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/list$(DependSuffix)
	$(RM) $(IntermediateDirectory)/list$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "E:\msys\home\mcxiaoke\dsaac\ch3\.build-debug\list"


