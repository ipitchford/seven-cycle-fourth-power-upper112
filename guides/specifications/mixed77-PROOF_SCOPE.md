# Conditional endpoint exclusion for C5 strong-product C7 cubed

Status: all primary and independent verification gates have passed. The complete exclusion of size78 proves alpha(C5 strong-product C7 cubed) at most77.

Write H = C5 strong-product C7 squared and G = H strong-product C7. Vertices of H are indexed by 49x+7y+z for x in Z5 and y,z in Z7. Two distinct vertices are adjacent when every coordinate difference is 0, 1, or -1. All enumeration and trace comparisons below use this exact integer relation.

The independently replayed maximum-code census of H proves alpha(H)=23 and gives precisely two isometry classes. The group is D5 times (D7 squared semidirect S2), of order3920; both stabilizers are trivial. Its7840 labeled maximum codes form the catalogue used below. No enumeration of the128,537,780 labeled size22 codes is needed.

## Normalization and selected bands

Suppose that an independent78-set exists in G. Slice it along the last C7 coordinate into disjoint projected layers A0,...,A6. Each Bi = Ai union A(i+1) is an independent set of H, of size at most23. Put qi = 23-|Bi|. Then every qi is nonnegative and their sum is161-156=5. At least two qi are zero. The layer sizes are uniquely determined by the deficits:

    ai = (23 - sum(j=0..6) (-1)^j q(i+j)) / 2.

Enumerating all462 weak compositions of5 into7 parts and the14 cyclic rotations/reflections gives38 canonical profiles. For each profile, choose the lexicographically least dihedral image satisfying q0=0 and having a zero among positions1,2,3. Let d be the first such position. This choice is exhaustive: two distinct zero positions have cyclic separation at most3 after reflection. Applying an automorphism of H maps the maximum band B0 to one of the two catalogue representatives without changing the deficit profile. Bd remains an arbitrary member of the full7840-code catalogue.

The possible pairs (a0,ad) are:

- d=1: (9,14), (10,13), (11,12), (12,11), (13,10).
- d=2: (11,10), (12,11).
- d=3: (11,12).

This creates47040 band-pair cases before necessary-condition pruning.

## Transverse trace condition

For each of the other two C7 axes, the sum of the seven adjacent-band sizes is156. A code with at most one size23 band has sum at most23+6*22=155. Thus at least two size23 bands are required on each transverse C7 axis.

For each catalogued maximum H-code, record the ordered pair of unions of its layers(0,1) and(d,d+1), projected to C5 strong-product C7. These dictionaries have4480,5600,6580 keys for d=1,2,3. Restricting known B0 and Bd to any transverse adjacent window and projecting that transverse coordinate produces precisely such a pair whenever the full transverse band is a maximum H-code. At least two of seven window keys must therefore be present for each transverse axis.

A full scan of47040 band pairs retains950 cases. Merely passing this test does not construct an independent78-set.

## Consistent allocations

For each retained pair, introduce46 Boolean variables: one for every word in B0, indicating whether it lies in A0 or A1, and one for every word in Bd, indicating whether it lies in Ad or A(d+1). If d=1, the two descriptions of the shared A1 must agree. All confusable pairs among the known actual four-dimensional positions are forbidden.

Every maximum-code template matching a transverse pair key gives an exact partial Boolean assignment on the words inside that window. Require two matching windows on each transverse axis using a single global Boolean assignment. Enforce all possible (a0,ad) values for that selected distance. The primary implementation joins partial tables and uses implication closure; the independent audit constructs CNF from actual four-dimensional positions.

Of the950 cases,926 have no such assignment and24 survive: one d=1 band pair and23 d=3 band pairs. Enumerating all46-bit assignments, blocking only these original variables, gives11479 distinct assignments in28 pair/count cases. All38 canonical deficit profiles are still covered:34 profile cases for the d=1 pair, and one profile for each of23 d=3 pairs. Five d=1 count cases have model counts0,0,0,1,3; only six actual profiles have models, yielding eight profile/model instances. The d=3 cases have11475 models and all have layer sizes(11,12,10,12,11,11,11).

## Completing the surviving allocations

For every d=3 model, the known layers A1 and A3 force A2 to be an independent10-set in H outside the closed neighborhoods of A1 union A3. Exact integer branch search with graph-clique covers rejects all11475 such domains. The largest domain has31 vertices. This step is a complete finite search of the necessary A2 factor, and so no later layers need be assigned.

For each of the eight d=1 profile/model instances, enumerate all possible A3. If q2=0, A2 union A3 must be one of the7840 maximum codes, so the complete catalogue gives every choice. In the one remaining case, enumerate every independent A3 of the profile-prescribed size outside the closed neighborhood of A2. Seven instances have one candidate each; the remaining instance has111 candidates.

For each candidate, restrict the known four layers A0,...,A3 to every transverse adjacent window. If that transverse band is maximum, the resulting four projected rows must coincide exactly with the first four rows of a catalogued maximum H-code. All118 candidates fail to provide two matching transverse windows on at least one axis. Thus no d=1 allocation extends either.

## Scope and verification boundary

The full catalogue, case normalization, complete allocation enumeration, and residual replays have all passed. The chain above excludes independent sets of size78. By taking subsets, excluding78 implies alpha(G) at most77, without separately excluding larger cardinalities. It does not establish equality or a77-word construction, and no novelty claim is made here.

The primary computations are complete. Independent fresh catalogue/trace replay, all950 CNFs, all11479 Boolean model sets, all11475 residual A2 domains, and all eight d=1 profile/model cases have passed. The A2 audit checks an explicit4971-node proof forest; the d=1 audit independently enumerates all118 next-layer candidates and rejects them by exact four-row traces. No timeout, numerical infeasibility status, heuristic failure, or symmetry-restricted result is used as an upper-bound argument.
