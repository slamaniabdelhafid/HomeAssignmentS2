.PHONY: clean All

All:
	@echo "----------Building project:[ Tic_tac_toe - Debug ]----------"
	@cd "Tic_tac_toe" && "$(MAKE)" -f  "Tic_tac_toe.mk"
clean:
	@echo "----------Cleaning project:[ Tic_tac_toe - Debug ]----------"
	@cd "Tic_tac_toe" && "$(MAKE)" -f  "Tic_tac_toe.mk" clean
