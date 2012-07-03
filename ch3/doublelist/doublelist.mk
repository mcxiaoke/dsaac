##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=doublelist
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\msys\home\mcxiaoke\dsaac\ch3"
ProjectPath            := "E:\msys\home\mcxiaoke\dsaac\ch3\doublelist"
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
ObjectsFileList        :="E:\msys\home\mcxiaoke\dsaac\ch3\doublelist\doublelist.txt"
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
Objects=$(IntermediateDirectory)/dlist$(ObjectSuffix) 

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
$(IntermediateDirectory)/dlist$(ObjectSuffix): dlist.c $(IntermediateDirectory)/dlist$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "E:/msys/home/mcxiaoke/dsaac/ch3/doublelist/dlist.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/dlist$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dlist$(DependSuffix): dlist.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dlist$(ObjectSuffix) -MF$(IntermediateDirectory)/dlist$(DependSuffix) -MM "E:/msys/home/mcxiaoke/dsaac/ch3/doublelist/dlist.c"

$(IntermediateDirectory)/dlist$(PreprocessSuffix): dlist.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dlist$(PreprocessSuffix) "E:/msys/home/mcxiaoke/dsaac/ch3/doublelist/dlist.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/dlist$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/dlist$(DependSuffix)
	$(RM) $(IntermediateDirectory)/dlist$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "E:\msys\home\mcxiaoke\dsaac\ch3\.build-debug\doublelist"


