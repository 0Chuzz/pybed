import bedbindings

mk_var = bedbindings.mk_var
mk_op = bedbindings.mk_op
Var = bedbindings.Var
Node = bedbindings.Node

class Op:
      BED_NOP	= 0		# No ( binary Boolean ) operator */
      BED_VAR	= 0		# Variable ( same as BED_NOP ) */
      BED_ITE	= 0		# If-Then-Else ( same as BED_NOP ) */
      BED_K0  	= 1 		# Constant 0 */
      BED_PI1	= 2		# left-child */
      BED_PI2	= 3		# right-child */
      BED_NOR 	= 4
      BED_NLIMP	= 5 		# Not left-imply */
      BED_NPI1 	= 6 		# Not left-child */
      BED_NIMP 	= 7 		# Not imply */
      BED_NPI2 	= 8 		# Not right-child */
      BED_XOR	= 9
      BED_NAND	= 10
      BED_AND	= 11
      BED_BIIMP	= 12		# Logical equality */
      BED_IMP	= 13		# Imply */
      BED_LIMP	= 14		# left-imply */
      BED_OR	= 15
      BED_K1	= 16		# Constant 1 */
      BED_EXISTS	= 17		# Existential quantifier */
      BED_FORALL	= 18		# Universal quantifier */
      BED_SUBST	= 19		# Substitution */
      BED_ESUB	= 20		# Exists & Subst of all variables */
