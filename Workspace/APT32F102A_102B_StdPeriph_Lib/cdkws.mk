.PHONY: clean All Project_Title Project_Build

All: Project_Title Project_Build

Project_Title:
	@echo "----------Building project:[ apt32f102 - BuildSet ]----------"

Project_Build:
	@make -r -f apt32f102.mk -j 6 -C  "D:/OneDrive/Works/Work Storage/Project/MCU/APT32F102/APT32F102A_Lib/APT32F102A_102B_StdPeriph_Lib_V1_15_20221105/Source" 


clean:
	@echo "----------Cleaning project:[ apt32f102 - BuildSet ]----------"

