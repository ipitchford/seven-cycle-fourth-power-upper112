# Citation and prior-art audit — 5 October 2026

This is a bounded retrospective paper-preparation check, not proof of novelty.
The earlier source-level audit and the following primary sources were used.

1. Baumert et al., A combinatorial packing problem, SIAM–AMS Proceedings 4,
   Computers in Algebra and Number Theory (1971), pp.97–108.
   https://oeis.org/A003012/a003012.pdf . The retained 12-page scan was examined
   during research: pp.106–107 treat the cubic maximum33; maximum square codes
   and the recursive upper bound are historical ingredients. The present bundle
   separately replays the needed finite facts rather than relying on the scan.
2. S. C. Polak and A. Schrijver, New lower bound on the Shannon capacity of C7
   from circular graphs, Information Processing Letters143 (2019),37–40.
   DOI https://doi.org/10.1016/j.ipl.2018.11.006 . Table1 in
   https://arxiv.org/html/1808.07438v2 records108–115 and attributes the upper
   recursion to Baumert et al. Journal metadata also checked at
   https://ir.cwi.nl/pub/30364 . This is the historical comparison for112;
   Polak and Schrijver's principal result concerns dimension5.
3. N. Itty, C. D. Rosin, C. Carstensen and D. Reichman, Improved lower bounds
   for the Shannon capacity of odd cycles, arXiv:2607.21517v2 (30 July2026).
   https://arxiv.org/html/2607.21517v2 . Section2 records108 and leaves the
   fourth-power value unknown. The source concerns improved constructions in
   other powers and does not prove108 optimal.
4. Y. Gao, A Recursive Construction Improving the Lower Bound on the Shannon
   Capacity of C7, arXiv:2607.27869v1 (30 July2026).
   https://arxiv.org/html/2607.27869v1 . Definition3 and Lemma4 define the
   construction used in the method-specific square-gadget theorem.

The 2026 arXiv version pages and full HTML, and the Polak/Schrijver primary
record, were rechecked during this preparation. No broader priority claim is
inferred from a negative search. The original 108 construction is attributed
to Vesel and Zerovnik (2002) through the historical source; its original full
coordinate list was not recovered. The original four bibliography entries are cited
in the manuscript and all cited works appear in the bibliography.

## Review-response update —5 October2026

5. A.Vesel and J.Žerovnik, *Improved lower bound on the Shannon capacity of C7*, Information Processing Letters81(5)(2002),277–282, DOI10.1016/S0020-0190(01)00229-0. The publisher abstract at https://www.sciencedirect.com/science/article/abs/pii/S0020019001002290 confirms the108 construction. Direct DOI retrieval failed in this revision; no full-text verification of that original construction is claimed. The supplied literal108 witness is checked independently.
6. P.Buys, S.Polak and J.Zuiddam, *Lean-verified lower bounds for the Shannon capacity of odd cycles*, arXiv2607.29681v1,31July2026, https://arxiv.org/html/2607.29681v1 . Section2 was read in full. Its valid tuples correspond to the private-pair gadgets used here: the neighbourhood condition makes endpoint collisions impossible between distinct centres. The first product coordinate is exactly the cardinality objective optimized in the square-factor certificate. The106 limitation therefore transfers for two square factors; higher-dimensional iteration remains outside its scope. The reported Lean formalization was not rebuilt here.

Live bounded queries also included the original Vesel title and `C7 upper bound112 independence fourth power`. No earlier equivalent112 result was established by this search; that is not proof of novelty. The construction papers address lower bounds in higher powers, not a fourth-power upper-bound exclusion. The complete cubic census and mixed77 bound are presented as explicit supplied computational prerequisites without an unsupported historical priority claim.
