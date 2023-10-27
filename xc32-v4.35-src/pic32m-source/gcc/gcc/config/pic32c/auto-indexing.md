;; ARM Thumb-2 peephole patterns to substitute a "load + increment" sequence with 
;;  a "load-with-pre-inc" insn.

(define_predicate "LDRB_PINC_OFF"
  (and (match_code "const_int")
       (match_test "INTVAL (op) == 1")))
(define_predicate "LDRH_PINC_OFF"
  (and (match_code "const_int")
       (match_test "INTVAL (op) == 2")))
(define_predicate "LDR_PINC_OFF"
  (and (match_code "const_int")
       (match_test "INTVAL (op) == 4")))

(define_predicate "LDRB_PDEC_OFF"
  (and (match_code "const_int")
       (match_test "INTVAL (op) == -1")))
(define_predicate "LDRH_PDEC_OFF"
  (and (match_code "const_int")
       (match_test "INTVAL (op) == -2")))
(define_predicate "LDR_PDEC_OFF"
  (and (match_code "const_int")
       (match_test "INTVAL (op) == -4")))

(define_code_iterator any_extend  [zero_extend sign_extend]         )
(define_mode_iterator any_mode    [QI HI]                           )
(define_mode_attr     any_inc_off [(QI "LDRB_PINC_OFF") (HI "LDRH_PINC_OFF")] )
(define_mode_attr     any_dec_off [(QI "LDRB_PDEC_OFF") (HI "LDRH_PDEC_OFF")] )

;; ldrb ri, [rj, #1]
;; adds rj,#1
;;
;; ldrb ri, [rj, #1]!

(define_peephole2
  [(set (match_operand:SI 0 "arm_hard_general_register_operand" "")
    (any_extend:SI
      (mem:any_mode
        (plus:SI (match_operand:SI 1 "arm_hard_general_register_operand" "")
                 (match_operand:SI 2 "<any_inc_off>") ))))
    (set (match_dup 1)
      (plus:SI (match_dup 1) (match_dup 2)))]

  "TARGET_32BIT && flag_auto_indexing 
    && (REGNO(operands[0]) != REGNO(operands[1]))"

  [(set (match_dup 0)
    (any_extend:SI (mem:any_mode (pre_inc:SI (match_dup 1)))))]
  ""
)

;; ldrb ri, [rj, #-1]
;; adds rj,#-1
;;
;; ldrb ri, [rj, #-1]!

(define_peephole2
  [(set (match_operand:SI 0 "arm_hard_general_register_operand" "")
    (any_extend:SI
      (mem:any_mode
        (plus:SI (match_operand:SI 1 "arm_hard_general_register_operand" "")
                 (match_operand:SI 2 "<any_dec_off>") ))))
    (set (match_dup 1)
      (plus:SI (match_dup 1) (match_dup 2)))]

  "TARGET_32BIT && flag_auto_indexing 
    && (REGNO(operands[0]) != REGNO(operands[1]))"

  [(set (match_dup 0)
    (any_extend:SI (mem:any_mode (pre_dec:SI (match_dup 1)))))]
  ""
)

;; ldr ri, [rj, #4]
;; adds rj,#4
;;
;; ldr ri, [rj, #4]!

(define_peephole2
  [(set (match_operand:SI 0 "arm_hard_general_register_operand" "")
    (mem:SI
      (plus:SI (match_operand:SI 1 "arm_hard_general_register_operand" "")
               (match_operand:SI 2 "LDR_PINC_OFF") )))
    (set (match_dup 1)
      (plus:SI (match_dup 1) (match_dup 2)))]

  "TARGET_32BIT && flag_auto_indexing 
    && (REGNO(operands[0]) != REGNO(operands[1]))"

  [(set (match_dup 0)
    (mem:SI (pre_inc:SI (match_dup 1))))]
  ""
)

;; ldr ri, [rj, #-4]
;; adds rj,#-4
;;
;; ldr ri, [rj, #-4]!

(define_peephole2
  [(set (match_operand:SI 0 "arm_hard_general_register_operand" "")
    (mem:SI
      (plus:SI (match_operand:SI 1 "arm_hard_general_register_operand" "")
               (match_operand:SI 2 "LDR_PDEC_OFF") )))
    (set (match_dup 1)
      (plus:SI (match_dup 1) (match_dup 2)))]

  "TARGET_32BIT && flag_auto_indexing 
    && (REGNO(operands[0]) != REGNO(operands[1]))"

  [(set (match_dup 0)
    (mem:SI (pre_dec:SI (match_dup 1))))]
  ""
)
