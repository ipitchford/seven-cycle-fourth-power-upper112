# Compact adjacent component, format A113-v1

This is a new export and replay adapter. All historical files remain unchanged.
The component is conditional at target 113: the separately registered
nonadjacent component and the mixed-product upper bound 77 are dependencies.
It is not a solution of the original 108 versus 109 problem.

## Canonical mathematical evidence

The component manifest gives graph `C7^strong4`, target 113, exactly the requested
catalogue roots, the representative and orbit-size hashes, and the mode for each
root. A complete component requires exactly roots 0 through 1015. Roots
0, 500, 925, 970, and 1015 retain `all9`; the other roots retain
`restricted17-16`. A pilot must name its proper subset and cannot emit a complete
component status.

Each root has one gzip JSON-lines archive, with one record for each scalar pair
in the freshly reconstructed root-local order. The second band is not stored:
the scalar generator determines it. A record has local index, overlap, role,
variable and clause counts, exact DIMACS hash, and additions-only RUP proof.
Its role is one of:

* `M`: the middle necessary formula is refuted.
* `J`: the joint middle/fourth-row necessary formula is refuted.
* `E`: the joint formula plus every retained physical blocking clause is refuted.
  This record also contains the ordered, distinct physical `(X,Y)` models and
  their exact completion-certificate references.

Only the final exclusion is retained. A joint proof already excludes every
physical assignment represented by its necessary formula; its intermediate
middle SAT record adds no exclusion evidence. An exhausted family is represented
by its final blocked formula and all physical blocks; the first SAT witness adds
no coverage. The exporter nevertheless checks conservation of every original
scalar case, SAT family, model, and exhaustion case before discarding intermediate
records. It records their source-file hashes and origin global/local identities.

Old proof deletion lines are omitted. This is sound because the checker retains
all clauses: reverse unit propagation is monotone under adding already justified
clauses. Addition bytes and their order are unchanged. Final empty clauses are
mandatory and are checked, never inferred from a solver status. The conversion
receipt counts original additions/deletions and retained additions.

## Exact completion evidence

Each retained model stores sorted 3D word lists X and Y. The verifier reconstructs
the original four-layer prefix `(B0\\X, X, B1\\X, Y)` and every physical variable
in the frozen encoder. It checks original 4D independence, the mode's cardinality
pairs, model uniqueness, and complete physical blocking. Auxiliary assignments
are neither retained nor blocked.

Each root's small dual-vector file stores positive integer row multipliers and
a positive denominator. Row numbering is dimensions 1 through 4, coordinate
subsets in lexicographic order, and starts in lexicographic order, with capacities
33, 10, 3, 1. All 2401 original vertices and their closed neighborhoods are rebuilt.
For prefix S, row coverage W and row constant C, the exact numerator is

    |S| D + C - sum(W(v), v in S)
      + sum(max(0,D-W(v)), v outside N[S]).

The verifier checks the retained numerator equals this arbitrary-integer result
and is strictly below 113 D. It checks each row's residual capacity is
nonnegative. No floating-point result or solver status is used in replay.

## Fresh reconstruction and conservation

Replay compiles vendored C++ sources into a new temporary directory, generates
all 16,672,544 labelled maximum 33-codes from the complete census, reruns the
selected adjacent scalar scan with overlaps 16 through 30, and independently
generates the complete anchored four-row dictionary for each requested root.
Middle and joint dictionaries are derived from the fresh anchored records.
For every scalar pair, the C++ checker reconstructs exactly the selected M/J/E
formula, checks its DIMACS hash, and checks every RUP addition through the
verified empty clause. It rejects missing, duplicated, reordered or extra cases,
unknown roles, wrong modes, malformed literals, and trailing data.

Historical adapters are explicit: five-root all9 combined archive; roots 1–8
raw-deletion per-root archives; roots 9–16 additions-only per-root archives;
roots 17–200 compressed legacy batches; 811 native learned-candidate roots.
Canonical identity is `(root, local_pair_index)`. Batch-dependent global indices
are provenance only. The exporter checks them against each original scalar
stream and records the first global index and exact source-stream hash.

The export binds the completed four-role ledger, its exact accepted evidence
receipts, source summaries, proof archives, enumerations and dual archives.
These are provenance bindings, not paths the portable mathematical replay opens.
The portable replay requires only the canonical package and its vendored sources.
It does not reopen the 21 GiB historical reference closure.

## Pilot and independent gates

The initial mixed pilot covers roots 6, 9, 17, 207, and 970: both early formats,
legacy compressed transport, current native transport, and historical all9,
including exhausted physical families. Before a full export, require independent
source/conversion review, fresh reconstruction/RUP/geometry replay, and rejected
negative controls for omitted/duplicate/reordered scalar cases, wrong root/mode,
altered formula/proof, omitted/altered model, malformed dual, wrong exact cost,
and trailing archive data. The independent reviewer must not substitute old
PASS receipts for this pilot's fresh replay.

The approximately 0.88 GiB existing per-root proof archives set a practical
target below 2 GiB. Only final proofs are exported once; no formula transports,
scalar streams, request packets or full SAT auxiliary models are copied.
Actual output bytes and peak replay memory will be measured in the pilot.
No full export or global theorem promotion follows from a size estimate.

## Final composition interface

The replay receipt states component A, target 113, graph, exact roots and mode
map, census hashes, mathematical dependencies, case/family/model counts,
canonical evidence hashes, verifier source hashes, and fresh replay status.
Global composition must separately bind N covering distance-2/3 maximum-band
pairs on the same census and verify both components cover all 1016 roots.
Neither an A receipt nor an N receipt alone asserts a global independence bound.
