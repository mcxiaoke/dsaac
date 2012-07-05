##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=notes
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\msys\home\mcxiaoke\dsaac\ch3"
ProjectPath            := "E:\msys\home\mcxiaoke\dsaac\ch3\notes"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mcxiaoke
Date                   :=2012/7/5
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
C_CompilerName         :=gcc -std=c99
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="E:\msys\home\mcxiaoke\dsaac\ch3\notes\notes.txt"
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
Objects=$(IntermediateDirectory)/note$(ObjectSuffix) 

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
$(IntermediateDirectory)/note$(ObjectSuffix): note.c $(IntermediateDirectory)/note$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "E:/msys/home/mcxiaoke/dsaac/ch3/notes/note.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/note$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/note$(DependSuffix): note.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/note$(ObjectSuffix) -MF$(IntermediateDirectory)/note$(DependSuffix) -MM "E:/msys/home/mcxiaoke/dsaac/ch3/notes/note.c"

$(IntermediateDirectory)/note$(PreprocessSuffix): note.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/note$(PreprocessSuffix) "E:/msys/home/mcxiaoke/dsaac/ch3/notes/note.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/note$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/note$(DependSuffix)
	$(RM) $(IntermediateDirectory)/note$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "E:\msys\home\mcxiaoke\dsaac\ch3\.build-debug\notes"


