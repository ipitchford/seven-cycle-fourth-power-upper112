---
abstract: |
  We establish the computer-assisted bounds $108\leq\alpha(C_7^{\boxtimes 4})\leq112$, and hence $\alpha(C_7^{\boxtimes 5})\leq392$. The upper bound reduces a hypothetical 113-word code to two exhaustive cases on its maximum three-dimensional bands. A complete catalogue of 1,016 isometry classes supplies the necessary boundary relations. Exhaustive constraint replay and checked Boolean refutations establish their respective allocation obligations, and integer sums of packing inequalities exclude every surviving completion. Three large families are handled by complete unions of partial assignments and exact uniform bounds rather than physical enumeration. Separately, we classify all 1,003,520 oriented boundary traces of maximum square codes by their largest cubic extension, and introduce a saturation-excess parameter for balanced 112-word codes. These results do not determine $\alpha(C_7^{\boxtimes 4})$. We also determine the exact maximum, 106, within Gao's product construction when both factors are two-dimensional gadgets, allowing nonmaximum seeds. An exact feasible moment vector also identifies a limitation of a specified degree-three relaxation: that relaxation cannot exclude sizes 109 through 112.
author:
- Anonymous
date: Candidate research manuscript --- 5 October 2026
title: An upper bound of 112 for the fourth strong power of the seven-cycle
---

::: center
Computer-assisted result with a portable exact certificate.\
The exact independence number remains open.
:::

# 1 Problem and scope

The vertices of $C_7^{\boxtimes d}$ are the words in $(\mathbb Z/7\mathbb Z)^d$. Distinct words are adjacent when every coordinate difference belongs to $\{0,1,-1\}$. Thus a code is independent exactly when each pair has a coordinate difference in $\{2,3,4,5\}$. In dimension four there are 2,401 vertices, each of degree 80, and 96,040 edges.

The published construction of size 108 is attributed to Vesel and Žerovnik \[5\]; the historical table in Polak and Schrijver records the fourth-power interval 108--115 \[2\]. The present upper bound reduces that historical upper endpoint by three. The input upper bound 115 comes from the recursive inequality attributed there to Baumert et al.; it is not the main new result of Polak and Schrijver. Itty et al. explicitly retain the fourth-power independence number as unknown in their July 2026 preprint \[3\]. Our supplied 108-word witness is checked directly; the lower bound does not rely on an optimizer report. We make no claim to historical priority from the bounded literature search. In particular, square partitions and compatible layer sequences are established methods, including the classical computation of $\alpha(C_7^{\boxtimes 3})=33$ \[1\].

Appendix A defines the trace predicates, encoding and coverage invariants. Our main conclusion uses finite computations. The ordinary reductions are proved below; the finite lemmas specify their quantified domains and computational evidence. The original certificate archives are preserved unchanged, with new acceptance receipts and a dated supersession guide recorded separately. Appendix B gives the reproduction map.

# 2 Bands and exhaustive normalization

Write $H=C_7^{\boxtimes 3}$. The input bounds are $$\alpha(C_7)=3,\qquad \alpha(C_7^{\boxtimes 2})=10,\qquad \alpha(H)=33,
 \qquad \alpha(C_5\boxtimes H)\leq77.$$ The first three values and the mixed upper bound have retained exact replays. Classifying maximum 33-word codes is a separate obligation from excluding 34 words; both are retained.

For a code $S\subseteq C_7^{\boxtimes 4}$, fix one coordinate and let $A_i\subseteq H$ be the words in layer $i$. Set $a_i=|A_i|$ and $B_i=A_i\cup A_{i+1}$, with subscripts modulo 7. Projection is injective on two adjacent layers: a repeated projected word would give an edge. The same observation shows that $B_i$ is independent in $H$.

#### Lemma 2.1. {#lem:normal .unnumbered}

If $|S|=113$, then $14\leq a_i\leq19$ and the deficits $q_i=33-|B_i|$ satisfy $q_i\geq0$ and $\sum_iq_i=5$. Either two maximum-band indices have cyclic distance 2 or 3, or the layer sizes are a rotation of $(16,17,16,16,16,16,16)$.

::: proof
*Proof.* The other six layers can be covered by three disjoint adjacent pairs, so $a_i\geq113-3\cdot33=14$. The neighboring band bound gives $a_i\leq19$. Each point is counted in two bands, hence $\sum_iq_i=231-226=5$. At least two of the seven deficits vanish. If their indices contain no nonadjacent pair, there are exactly two of them, since a seven-cycle has no triangle. Translate the indices so that $q_0=q_1=0$. The other five deficits are positive and have sum 5, so they all equal 1. Solving the seven equations $a_i+a_{i+1}=33-q_i$ gives the displayed profile. ◻
:::

A direct independent enumeration corroborates this reduction: exactly 462 integer layer profiles have sum 113 and adjacent sums at most 33. Of these, 455 contain nonadjacent maximum bands, and seven are the rotations above. This finite check supplements the proof; it does not replace it.

#### Lemma 2.2 (Mixed contraction). {#lem:contract .unnumbered}

Replacing three consecutive layers $A_0,A_1,A_2$ by $A_0\cap A_2$ gives an independent code in $C_5\boxtimes H$ of size $|S|-|A_0\cup A_1\cup A_2|$.

::: proof
*Proof.* The new first layer is compatible with $A_3$ because it is contained in $A_2$, and with $A_6$ because it is contained in $A_0$. All other consecutive-layer conditions are inherited. Adjacent original layers are disjoint as projected sets, so the asserted size follows by inclusion--exclusion. ◻
:::

## Prerequisites and their provenance

The values $\alpha(C_7)=3$, $\alpha(C_7^{\boxtimes 2})=10$ and $\alpha(C_7^{\boxtimes 3})=33$ are classical; see Baumert et al. \[1\] and the later account in Polak--Schrijver \[2\]. The package recomputes the required small cases. The following census and mixed bound are explicit computational prerequisites supplied here, without a claim that this work first established them.

#### Proposition 2.3 (Complete cubic census). {#prop:census .unnumbered}

Every independent 33-subset of $H$ is isometric to exactly one of the 1,016 supplied representatives. Their orbits contain 16,672,544 distinct labelled codes in total.

::: proof
*Finite proof route.* For layer sizes $a_i$, the square-band deficits $10-a_i-a_{i+1}$ are nonnegative and sum to four. There are 20 deficit patterns modulo rotation and reflection, each admitting a zero at the initial band. Enumerate every split of each of the three maximum-square representatives, then every subsequent layer of the required size compatible with its predecessor, checking the closing compatibility at the end. This exhaustive recursion retains 4,560 normalized configurations. Exact isometry classification gives the following orbit sizes; the weighted sum is the claimed labelled total. The replay also independently excludes 34 words, so the enumerated codes are maximum. Two orbit calculations agree; they are not two independent exhaustive searches. ◻
:::

::: center
       Orbit size   Number of orbits
  --------------- ------------------
           16,464              1,011
            8,232                  1
            5,488                  3
            2,744                  1
    Total classes              1,016
:::

#### Lemma 2.4 (Mixed-cycle prerequisite). {#lem:mixed77 .unnumbered}

Every independent subset of $C_5\boxtimes C_7^{\boxtimes3}$ has at most 77 vertices.

::: proof
*Finite proof route.* Slice a hypothetical 78-set along a seven-cycle factor. Its bands lie in $J=C_5\boxtimes C_7^{\boxtimes2}$, with $\alpha(J)=23$. The supplied complete census has two orbits of size 3,920 each, obtained from 14 normalized records. Seven band deficits sum to five, forcing two maximum bands and giving 38 normalized profiles. Fix the first band to either representative and let the second range over all 7,840 labelled codes at distances one, two or three: 47,040 pairs. Exact necessary transverse union traces retain 950 pairs. Consistent physical allocations retain 24 pairs, with 11,479 assignments in 28 pair/count cases; all 57 surviving pair/profile combinations are mapped explicitly. The 11,475 distance-three assignments have no required ten-point middle layer, by complete residual search and a separately checked 4,971-node branch/clique-cover forest. The remaining eight distance-one profile/model instances yield exactly 118 next-layer candidates; each fails the necessary four-row trace relation on a transverse axis. The supplied integer joins, residual checks and separate CNF/RUP replay check every case. Thus 78 is impossible; any larger set contains a 78-subset. This proves an upper bound, not equality at 77. ◻
:::

The dependency structure is $$\begin{gathered}
\text{small capacities + cubic census + mixed bound 77}\\
\Downarrow\\
\text{normalization + N/A + integer completion}\\
\Longrightarrow\alpha(C_7^{\boxtimes 4})\leq112
\Longrightarrow\alpha(C_7^{\boxtimes 5})\leq392.\\[3pt]
\text{cubic census}\Longrightarrow\text{square-trace classification};\\
\text{restricted 32-census}\Longrightarrow E=0\text{ exclusion}.\\
\text{square gadget census}\Longrightarrow\text{method maximum 106};\\
\text{specified moment model}\Longrightarrow\text{feasibility at 109--112}.
\end{gathered}$$ The last two conclusions are independent auxiliary results, not premises of the main exclusion. The moment model uses the stated capacities and mixed bound to define its rows. The exact value and the remaining 112-word branches are unresolved.

# 3 The two complete finite obligations

The full maximum-code catalogue has 1,016 classes under translations, coordinate reflections and coordinate permutations, representing 16,672,544 labelled codes. These are all maximum codes, not merely codes invariant under a selected symmetry. Symmetry is used to normalize one band, while all compatible labelled partner bands remain in the search.

## Nonadjacent maximum bands

Normalize a nonadjacent pair to $B_0,B_d$, where $d=2$ or 3. Choose the member in the smaller catalogue class first, then normalize it within $H$. Reflection of the outer cycle makes either cyclic orientation available. The second band ranges over every labelled maximum code whose class is at least the first class. Retaining equal classes is essential.

The 66 Boolean allocation variables divide the two maximum codes into their four physical layers. With $u=|A_0|$ and $v=|A_d|$, the necessary domains are $$14\leq v\leq u\leq19\quad(d=2),\qquad
 14\leq u,v\leq19\quad(d=3).$$ For $d=2$, the intervening band gives $u-v=q_1\geq0$. Lemma 2.2 also implies $|B_0\cap B_2|\leq30$: the union of $A_0,A_1,A_2$ has at least 36 words, whereas $B_0$ has 33. Swapping the selected bands by $t\mapsto d+1-t$ replaces $(u,v)$ by $(33-v,33-u)$, preserving these domains. The class ordering is therefore sound only when all first classes are covered, as they are here.

In every transverse coordinate at least two of the seven adjacent-layer windows must also be maximum bands. Their known projected rows must occur in the complete cubic catalogue. This supplies necessary allocation constraints. The indices of the two qualifying windows need not themselves be adjacent.

#### Lemma 3.1 (Finite obligation N). {#lem:N .unnumbered}

Every 113-word independent set possessing a nonadjacent pair of maximum bands is excluded by the complete allocation and completion certificates.

The finite evidence covers all 1,016 first classes at both offsets. Twenty-one classes use the stronger scan over every second class; the remaining 995 use the class-ordered scan. The exact disjoint composition contains 27,718 retained pair records and 4,356,002 physical allocations. Each allocation has an exact completion bound at most 112.

Three additional offset-three families are covered by complete unions of partial allocation assignments. They have uniform upper bounds 107, 105 and 104, respectively. Their original incomplete physical-enumeration records are retained. A complete cube union is not relabelled as a complete list of physical assignments. Every actual target allocation must lie in the union, and every cube must be bounded; overlap between cubes is harmless. Section 4 gives the bound used for this route.

## The adjacent profile

After Lemma 3.1, Lemma 2.1 forces the 17/16 profile. Normalize $B_0$ and enumerate every labelled $B_1$. Put $c=|B_0\cap B_1|$. The middle layer $A_1$ gives $c\geq17$. The contracted five-layer code has size $47+c$, so $c\leq30$ by the mixed upper bound 77. The retained scan covers the wider interval 16--30.

Choose $X=A_1\subseteq B_0\cap B_1$ with $|X|=17$, and a physical fourth layer $Y=A_3$ with $|Y|=16$. Then $A_0=B_0\setminus X$ and $A_2=B_1\setminus X$. The Boolean model enforces independence and adjacent-layer compatibility, together with the complete maximum-code trace conditions on every transverse direction. At least two of its seven windows must qualify. When a projected point has two possible physical lifts, the model retains both choices and enforces their exact selection relation.

#### Lemma 3.2 (Finite obligation A). {#lem:A .unnumbered}

For every first maximum-band class, every physical four-layer prefix with the forced profile is excluded by the allocation and exact completion certificates.

The finite evidence contains 7,351,160 scalar pair cases, 928 exhausted physical families and 12,779 retained prefixes. Every rejected formula has a checked refutation. For surviving families, blocking clauses name the physical selections only; a final refutation proves that no further physical assignment remains. All retained prefixes have exact completion bounds at most 112. Five historical starting classes were checked over a broader profile domain containing the required 17/16 case.

Separate full-class records verify the complete dictionaries, the regenerated formulas and their refutations, and the original-graph completion inequalities. The 205 carried classes and 811 later classes form an exact disjoint partition. A successful computation for one class alone would not establish this lemma.

#### Theorem 3.3 (Computer-assisted upper bound). {#thm:112 .unnumbered}

The completed local exact certificates establish $108\leq\alpha(C_7^{\boxtimes 4})\leq112$.

::: proof
*Proof.* Lemma 2.1 gives two exhaustive possibilities for a 113-word code. Lemma 3.1 excludes the first and forces the profile excluded by Lemma 3.2. Thus no 113-word code exists. Any larger independent set would contain a 113-word subset. The supplied 108-word witness has 108 distinct vertices, and all 5,778 pairs pass the direct coordinate-difference test. ◻
:::

#### Corollary 3.4. {#corollary-3.4. .unnumbered}

$\alpha(C_7^{\boxtimes 5})\leq392$.

::: proof
*Proof.* Each of the seven adjacent bands in one coordinate projects injectively to an independent subset of $C_7^{\boxtimes 4}$, of size at most 112. Their total size is twice the code size, so $2|S|\leq7\cdot112=784$. ◻
:::

This finite-power upper bound does not determine the Shannon capacity.

# 4 Exact completion inequalities {#sec:dual}

For each nonempty set of $k$ coordinate axes and an adjacent pair on each selected axis, let $R_i$ denote the corresponding product window. Its capacity $b_i$ is 33, 10, 3 or 1 for $k=1,2,3,4$, respectively. Injective projection onto the unrestricted coordinates proves these inequalities. There are $\sum_{k=1}^4\binom4k7^k=4,095$ rows. Choose integers $Y_i\geq0$ and $D>0$, and put $W(v)=\sum_{i:v\in R_i}Y_i$.

#### Lemma 4.1 (Fixed-prefix repair). {#lem:repair .unnumbered}

Let $F$ be an independent fixed prefix and let $V_F$ be the vertices outside its closed neighborhood. Every independent completion $S\supseteq F$ satisfies $$\begin{equation}
\label{eq:repair}
 D|S|\leq\sum_i b_iY_i+\sum_{u\in F}(D-W(u))
              +\sum_{v\in V_F}\max\{0,D-W(v)\}.
\end{equation}$$

::: proof
*Proof.* Write $S=F\sqcup T$, where $T\subseteq V_F$. Summing the packing inequalities gives $\sum_{u\in F}W(u)+\sum_{v\in T}W(v)\leq\sum_i b_iY_i$. Subtract the fixed contribution, add $D|F|$, and bound the missing coefficient of each possible residual vertex by its nonnegative unit repair. This gives 1. ◻
:::

An integer numerator $N<113D$ gives $|S|\leq\lfloor N/D\rfloor\leq112$; it need not satisfy $N\leq112D$. All 2,401 vertices, window incidences and forbidden neighborhoods are reconstructed by the checker. Floating-point optimization supplies candidate weights only; the accepted inequality uses integer arithmetic.

For an offset-three cube, the fixed allocations occupy outer layers 0,1,3,4 and contain 66 words. Put $R=\{2,5,6\}\times(\mathbb Z/7\mathbb Z)^3$. Let $L$ be an exact lower bound on the prefix weight $\sum_{u\in F}W(u)$ over the cube and the required half-cardinality domains. The same argument gives $$\begin{equation}
\label{eq:cube}
 D|S|\leq66D+\sum_i b_iY_i-L+\sum_{v\in R}\max\{0,D-W(v)\}.
\end{equation}$$ The cube minimization is replayed from its literal assignments and integer weights. Allowing invalid allocations can only decrease $L$; ignoring conflicts between $R$ and the prefix can only enlarge the residual term. Both relaxations therefore preserve the upper bound. Incomplete cube generation, unchecked minimization, or a time limit is not accepted as an exclusion.

# 5 Complete maximum-square boundary traces

Let $Q$ be a maximum independent set of size 10 in $C_7^{\boxtimes 2}$, and let $A\subseteq Q$. Define $E(Q,A)$ to be the largest size of an independent set in $C_7^{\boxtimes 3}$ whose first two layers are exactly $A,Q\setminus A$. There are 980 labelled choices of $Q$, in three plane-isometry classes, and 1,024 oriented splits for each. A separate delivered package determines all 1,003,520 values:

::: {#tab:traces}
    Maximum extension   Labelled oriented traces
  ------------------- --------------------------
                   30                      1,960
                   31                     29,008
                   32                    709,128
                   33                    263,424
                Total                  1,003,520

  : Complete oriented maximum-square trace classification.
:::

Every value has a directly checked attaining code. Complete maximum 33 coverage decides which traces attain 33. The remaining negative bounds use elementary layer capacities together with fourteen exceptional two/eight-split exclusions.

Orient each exceptional trace so that $|A_0|=2$ and $|A_1|=8$. A size 32 extension would force a two-point third layer $A_2$ and maximum square unions $U=A_3\cup A_4$ and $V=A_5\cup A_6$. The enumeration ranges over every possible two-point $A_2$ compatible with $A_1$, and every such maximum pair $U,V$. With $N[\cdot]$ the square closed neighborhood, put $M=U\cap N[A_2]$ and $M'=V\cap N[A_0]$. Moving any additional points from $A_4$ into $A_3$, and from $A_5$ into $A_6$, preserves the relevant unions and relaxes compatibility. The last four layers become $(U\setminus M,M,M',V\setminus M')$. Every layer of any size 32 cubic code has size between 2 and 8, so the enumeration retains mandatory sets only within that range. A size 32 completion exists precisely when one retained pair satisfies $N[M]\cap M'=\varnothing$. For each of the fourteen normalized traces, the exact enumeration has a unique feasible $A_2$ and 203 distinct mandatory sets on each side. It checks 41,209 pairs, with none compatible. Independent Cartesian enumeration of all 980 squares confirms the exclusions.

This is a classification of prescribed boundary traces, not a census of all 32-word cubic codes. In particular it does not independently decide the fourth-power balanced case.

# 6 A saturation-excess reduction at size 112

Suppose a 112-word code has no 33-word band in any coordinate. Every band then has size 32, and the odd-cycle equations force every coordinate layer to have size 16. For two axes $a,b$, let $B_{ab}(i,j)$ count the points in the corresponding adjacent two-coordinate window. Its entries are at most 10, and every row and column sums to 64. Define $$e_{ab}=\#\{(i,j):B_{ab}(i,j)=10\}-7,\qquad
 E=\sum_{a<b}e_{ab}.$$ In a row with $z$ entries equal to 10, comparison with seven nines gives $$\begin{equation}
\label{eq:defect}
 z-1=\sum_{j:B_{ab}(i,j)\leq8}(9-B_{ab}(i,j))\geq0.
\end{equation}$$ Consequently every $e_{ab}$ is nonnegative. It vanishes exactly when $B_{ab}=9J+P$ for a permutation matrix $P$.

Call a 32-word cubic code *restricted* when it has exactly one maximum square window in each of its three directions. A separately delivered complete census has 11,175 isometry classes and 183,864,464 labelled codes of this kind.

#### Proposition 6.1. {#prop:excess .unnumbered}

At most $2E$ of the 28 cubic bands are outside the restricted family. If $E=1$, exactly two are outside: one along each endpoint axis of the unique exceptional coordinate pair. Their common square window has size 8, and all other 26 cubic bands are restricted.

::: proof
*Proof.* For band $(a,i)$, sum $z-1$ over the three transverse directions to obtain a nonnegative defect $d_{a,i}$. This defect vanishes exactly for a restricted band. Summing 3 over rows and columns gives $\sum_{a,i}d_{a,i}=2E$, proving the first assertion. When $E=1$, one pair matrix has total deficit below 9 equal to 1. It has one entry 8, eight entries 10, and forty entries 9. The row and column of the 8 each have two tens; every other row and column has one. These give exactly the two exceptional bands asserted. ◻
:::

The exceptional pair matrix alone creates no integrality contradiction. Writing $B=9J+M$, the matrix $M$ has row and column sums 1 and one negative entry $-1$. Let $L_{ij}=1$ when $j-i\in\{0,1\}$ and zero otherwise. If $R_{ij}=1$ for $j-i\in\{1,3,5\}$, then $$L^{-1}=\tfrac{1}{2}(J-2R),\qquad
 N=L^{-1}BL^{-T}=J+RMR^T.$$ Thus the corresponding pair-count matrix $N$ is integral. Every entry of $RMR^T$ is at least $-1$, so $N$ is nonnegative; its row and column sums are 16. There are $7^2\binom{6}{2}^2 4!=264,600$ such labelled exceptional matrices. This is pair-marginal feasibility only, not a four-dimensional construction.

For a fixed restricted cubic anchor, a 16/16 allocation uses 32 shared Boolean variables. Each of its 21 transverse square traces must extend to a restricted cubic band when $E=0$. The complete canonical trace dictionary has 218 square-union classes and 18,184 oriented splits. All plane stabilizers must be retained when transporting a split to the anchor's original variables.

For $E=0$, requiring all 21 relations, a complete first pass over the 11,175 restricted anchor classes excludes 11,132 by checked binary-tree proofs and retains 43 with directly checked necessary allocations. There are no unresolved cases in this pass. These 43 allocations are not four-dimensional constructions. In particular, the successful exclusions at all 129 calibration anchors did not imply a complete atlas exclusion.

For the $E=0$ branch, one can now rebuild the trace dictionary using only retained classes. Every band of an actual code would have to belong to that family. More generally, start with the complete family $F_0$ and remove only anchors with checked complete refutations against the exact dictionary of the current family $F_k$. Induction shows that all bands of an actual $E=0$ code survive every step. A dictionary must be regenerated from all current representatives and all isometries; filtering one previously stored witness per trace is insufficient. The independent rebuild from the 43 retained classes has 1,286 allowed oriented splits and 63 explicit empty square-union domains. The second allocation pass excludes all 43 remaining classes by checked trees, containing 2,893 bytes in total. The first pass has 11,132 complete refutation trees totalling 40,130,324 bytes; partial search trees for its 43 satisfying cases are not refutation evidence.

#### Proposition 6.2 (Computer-assisted minimum-saturation exclusion). {#proposition-6.2-computer-assisted-minimum-saturation-exclusion. .unnumbered}

Under the no-33-band hypothesis at size 112, the saturation excess satisfies $E\geq1$.

::: proof
*Proof.* If $E=0$, every cubic band belongs to the complete restricted family $F_0$. The exact two-pass necessary-allocation computation gives $|F_0|=11,175$, $|F_1|=43$, and $F_2=\varnothing$. The induction above would place every actual band in $F_2$, a contradiction. This proof uses the complete checked removal trees, not the sample exclusions or native search status. A fresh replay from the sealed portable archive regenerated the complete census and both trace dictionaries, then checked all cases in 1,222.72 seconds. It consumed 40,133,217 proof bytes and left no unresolved cases within this conditional theorem. The new acceptance receipt records the complete census and both elimination passes; source identities and terminal observations accompany it. ◻
:::

#### Remaining cases (exploratory).

If $E=1$, choose a restricted anchor along one of the two endpoint axes in Proposition 6.1. It has only one exceptional transverse band, so at least 20 of the 21 restricted trace relations must hold for the same allocation. This is a sound necessary query without assuming a full 32-word census; it is distinct from the completed $E=0$ computation above. Allowing one failed transverse relation is a different necessary query. A complete 17-anchor sample of that query has 15 exclusions and two satisfying allocations. Thus a universal two-conflict assertion is false for the original dictionary. Moreover, the $E=0$ retained family cannot be transferred to $E=1$: an anchor excluded using all 21 relations may still occur when one or two transverse bands are exceptional.

# 7 An exact limitation of the square-factor gadget construction

This section concerns the construction of Gao \[4\], rather than arbitrary four-dimensional codes. In a graph with closed neighbourhoods $N$, a gadget has an independent seed $I$ of size $a$, disjoint private pairs $(r_i,q_i)$ with $r_i\in I$, $q_i\notin I$, all endpoints distinct, satisfying $N(q_i)\cap I=\{r_i\}$, complementary independent endpoint transversals $H,V$, and an independent auxiliary set $X$ disjoint from $N(H)\cap N(V)$. Write $t$ for the number of pairs and $s=|X|$. Gao's product of gadgets with triples $(a,t,s)$ and $(A,T,S)$ has cardinality $$F=(a-t)(A-T)+tS+sT.$$

#### Theorem 7.1. {#theorem-7.1. .unnumbered}

Among all such gadget pairs with both underlying graphs equal to $C_7^{\boxtimes 2}$, the largest product cardinality is exactly 106.

::: proof
*Proof.* Put $O=X\setminus(N(H)\cup N(V))$, $X_H=X\cap N(H)$ and $X_V=X\cap N(V)$. The endpoint condition makes these a disjoint partition of $X$. The independent sets $H\cup O\cup X_V$ and $V\cup O\cup X_H$ each have size at most ten. Hence $2t+s+|O|\leq20$. For seeds of size ten, a complete private-pair and orientation enumeration sharpens this to auxiliary ceilings $10,10,10,9,7$ for $t=0,1,2,3,4$, respectively, with no larger $t$. Together these conditions leave 616 integer triples.

For a fixed auxiliary set, form a graph of ordered confusable endpoint pairs. Adjacency requires four distinct endpoints, independence of the two first endpoints and of the two second endpoints, and the auxiliary condition for both cross pairs. A $t$-clique describes complementary transversals. The complete ten-point auxiliary catalogue has 980 labelled members in three isometry classes. None of their endpoint graphs contains a five-clique, so $s=10$ implies $t\leq4$ for every seed. Exact scalar enumeration then shows that only $$P=(9,4,10),\qquad Q=(9,5,9),\qquad R=(9,6,8)$$ can participate in a product above 104. Their pair scores are $105,106,107,106,106,105$ in the order $PP,PQ,PR,QQ,QR,RR$.

The triple $R$ is impossible. The complete eight-point auxiliary catalogue has 346,381 labelled members in 924 isometry classes. Their endpoint graphs contain exactly 866 six-cliques. The independent base $I\setminus\{r_i\}$ would require three vertices outside the closed neighbourhood of all twelve endpoints. Every one of the 866 cliques leaves at most two such vertices. Removing $R$ leaves a scalar upper bound of 106. A supplied $Q$ gadget attains 106 in its self-product; the literal construction has $16+45+45$ distinct words, and every one of its 5,565 pairs is checked in the original graph. ◻
:::

The portable replay regenerates the auxiliary catalogues, maximum-seed ceilings, endpoint graph enumerations, integer envelope and attaining code. Its fresh clean-extraction run passed in 14.63 seconds. It uses neither a cubic census nor the main fourth-power bound. The theorem allows different gadgets and nonmaximum seeds in the two square factors, but does not cover other decompositions or arbitrary codes. The known 108-word construction already exceeds this method's maximum.

Buys, Polak and Zuiddam \[6\], Section 2, express the construction as valid tuples $(I,S,f_0,f_1,X)$. For each $r\in S$, one image is $r$; the other is outside $I$ and has closed neighborhood intersecting $I$ only in $r$. Images for distinct centers cannot coincide, since their neighborhood intersections would differ. Thus the images give exactly the disjoint private pairs and complementary transversals used above. Conversely each gadget defines such maps. Their profile's first three coordinates are $(a,t,s)$ and its product's first coordinate is $F$. Therefore the maximum 106 transfers unchanged to two square-factor valid tuples. It does not limit their higher-dimensional iteration. Their paper reports Lean verification of those constructions; we have not rebuilt that formalization and make no Lean-verification claim for this upper bound.

# 8 An exact limitation of an invariant moment relaxation

The remaining gap motivates a separate question: can low-degree necessary conditions already exclude 109? We give an exact negative answer for one specified relaxation, called here the *two-block invariant degree-three relaxation*. This is a statement about the method, not about the existence of a code.

Average a hypothetical code under all translations, coordinate reflections and coordinate permutations. For each independent set $T$ with $|T|\leq3$, its averaged indicators motivate relaxation variables (pseudo-moments) $y_T$. These variables need not arise from any probability distribution on codes. Set $y_T=0$ for forbidden sets. Repeated vertices collapse by set union. There are 3,162 variables: one empty, one singleton, 30 pair and 3,130 triple orbits. For target cardinality $K$, impose $y_\varnothing=1$, nonnegativity, subset monotonicity, and $$\sum_{v\in V}y_{T\cup\{v\}}=K y_T\qquad(|T|\leq2).$$ For every adjacent product window $R$ of capacity $b_R$, impose $\sum_{v\in R}y_{T\cup\{v\}}\leq b_Ry_T$ for $|T|\leq2$. Include the five-cycle contraction inequalities from Lemma 2.2, both unconditioned and multiplied by $x_0$. Explicitly, for each axis and starting layer $i$, these are the moments of $$\sum_{v:\,v_a\notin\{i,i+1,i+2\}}x_v
 +\sum_{z\in(\mathbb Z/7\mathbb Z)^3}x_{(i,z)}x_{(i+2,z)}\leq77,$$ with the indicated coordinate inserted in position $a$.

The selected localizing matrix is the moment matrix of $x_0(1,(x_u)_{u\notin N[0]})(1,(x_u)_{u\notin N[0]})^T$; the absent matrix is that of $(1-x_0)(1,(x_u)_{u\ne0})(1,(x_u)_{u\ne0})^T$. Compress each matrix to the indicator vectors of the origin-stabilizer orbits. Their orders are 31 and 35. Impose positivity of these two compressions. This does not impose positivity on the other invariant subspaces of the full matrices.

#### Proposition 8.1 (Exact relaxation feasibility). {#prop:barrier .unnumbered}

The specified relaxation is feasible at every integer $K$ from 109 to 112. Consequently it cannot improve the upper bound 112 or decide whether a 109-word independent set exists.

::: proof
*Proof.* At $K=112$, the supplied rational vector satisfies all 156,291 linear rows exactly. They consist of 33 normalization/cardinality equations, 3,161 nonnegativity, 22,001 monotonicity, 131,040 packing, and 56 contraction inequalities. The verifier regenerates the complete rows. The two compressed matrices have exact kernels $(-111,1,\ldots,1)$ and $(-112,1,\ldots,1)$. Removing their constant coordinates leaves principal matrices of orders 30 and 34. All their leading principal minors are positive, as checked by fraction-free integer elimination. The kernel identities express each complete matrix as a congruence of its principal matrix, establishing positivity exactly.

For completeness, this feasibility descends to smaller cardinalities. Multiply a degree-$s$ moment by $f_s=(k)_s/(K)_s$. Cardinality follows from $f_{s+1}(K-s)=f_s(k-s)$. Every positive term of a packing or contraction row has degree at least that of its conditioning monomial, so scales by at most the factor on the right; nonnegativity and monotonicity are preserved.

To check matrix positivity, write a conditional compressed matrix as $T=\left(\begin{smallmatrix}p&d^T\\d&A\end{smallmatrix}\right)$, where $d\geq0$, $\mathbf 1^Td=Lp$ and $A\mathbf 1=Ld$. Sampling $l$ of $L$ points replaces $d$ by $r_1d$ and $A$ by $r_2A+(r_1-r_2)\operatorname{Diag}(d)$, where $r_1=l/L$ and $r_2=l(l-1)/(L(L-1))$. Its Schur complement is $$r_2\left(A-\frac{dd^T}{p}\right)
 +(r_1-r_2)\left(\operatorname{Diag}(d)-\frac{dd^T}{Lp}\right)\succeq0.$$ The first term is positive by the original matrix condition and the second by weighted Cauchy--Schwarz. Here $d$ contains orbit sums; $\operatorname{Diag}(d)$ is not in general the diagonal of $A$. For the selected matrix use $(k/K)\operatorname{Thin}_{k-1}^{K-1}(T_+)$. For the absent matrix use $$\operatorname{Thin}_{k}^{K}(T_-)
 +\frac{K-k}{K}\operatorname{Thin}_{k}^{K-1}(T_+),$$ embedding $T_+$ by zero rows for neighbors of the origin. These identities hold entrywise and preserve positivity. Apply them to $K=112$ and $k=109,110,111$. ◻
:::

The rational vector was recovered from numerical moments, but its verifier uses only integer arithmetic and the Python standard library. It completes in about five seconds in the reference environment. No numerical solver status is used as evidence for Proposition 8.1.

The full localizing matrices reject this particular point, including its thinning to 109. Reflection characters reduce those stronger conditions to ten representative blocks of order at most 255. A bounded numerical solve with all ten blocks was inconclusive: the returned point violated linear constraints and had negative block eigenvalues. It supplies neither a feasible certificate nor an improved graph bound.

# 9 Evidence, limitations and remaining problem

The accepted local proof checks separate four questions: completeness of the catalogue and necessary constraints; exhaustive coverage of allocations; validity of every exact completion bound; and full-class composition. Fresh checks reconstruct the mathematical objects rather than accepting numerical optimizer statuses. Corruption controls exercise omitted classes, incorrect domains, changed geometry, invalid proof leaves and incomplete proof streams.

Both main components cover all 1,016 maximum-band classes without unresolved cases. Earlier reference replays took 3,632 seconds for A and 3,595 seconds for N, within a 1.3 GiB memory limit. The new acceptance receipts separately identify the fresh review-stage executions. The 786,289,587-byte main archive preserves their exact checked bytes. Separate readbacks checked archive extraction, all 462 normalization profiles and all 5,778 pairs of the lower witness. Auxiliary archives separately replay the boundary-trace, minimum-saturation, square-gadget and moment-feasibility results. These internal computations do not constitute external peer review or reproduction by an outside researcher.

The target $\alpha(C_7^{\boxtimes 4})$ remains undetermined: the present result leaves the five possibilities 108 through 112. No 109-word construction and no exclusion of 109 has been obtained. The low-excess reductions above assume size 112 and absence of 33-word bands; they do not cover 112-word codes with a 33-word band, or smaller codes without further analysis. These distinctions remain part of the theorem scope, not merely limitations of the implementation.

## Reproduction and evidence map

The accompanying paper-and-evidence bundle contains this manuscript as PDF, LaTeX and readable Markdown, plus unchanged certificate archives. The bundle guide and machine-readable claim map identify each statement's proof, data and replay command. The main upper-bound archive is `c7-fourth-power-upper112.zip`; it contains both complete components and all prerequisite proofs. Its top-level verifier checks the 108-word witness and the exhaustive normalization before running the component replays. A fresh full run requires Python 3.10 or later, a C++17 compiler, and about 20 GiB of available disk space. The reference run took about two hours in total; actual runtimes depend on the machine. No SAT solver or numerical optimizer is needed to replay the proof.

The central trusted components and their mathematical interfaces are specified in Appendix A. The dependency and source map, copyable replay commands, acceptance environment and terminal receipts are retained with the evidence. An archive identity establishes which bytes were checked; it does not establish the adequacy of an encoding.

#### Availability and licensing.

The versioned candidate is associated with [Zenodo record 23160075](https://doi.org/10.5281/zenodo.23160075) and the [public research repository](https://github.com/ipitchford/seven-cycle-fourth-power-upper112). Original prose and data use CC0-1.0; original executable code uses MIT. Inherited notices remain in force. DOI registration and public availability are separate from mathematical correctness and external acceptance. The original Vesel--Žerovnik publisher abstract was available for bibliographic attribution; its full text was not obtained in this revision. The lower witness is checked directly, independently of that access limit.

#### Authorship and AI assistance.

The scholarly creator is Anonymous. Codex assisted the mathematical analysis, programming, computational checks and manuscript preparation. These internal checks are not external peer review. No human contribution is inferred from account ownership. The exact checkers, rather than model-generated prose or solver labels, provide the computational evidence.

#### Declarations.

This work uses finite graph data and has no human or animal participants. No funding or competing-interest information was supplied for this anonymous candidate; those declarations remain unspecified. The release remains an unrefereed candidate; publication implies no external acceptance or official research-assessment rating.

# A Finite-proof semantics and exhaustive coverage {#app:finite}

This appendix specifies the mathematical objects checked by the executable proof. A catalogue entry is a literal independent subset, not an abstract orbit label. Write $\mathcal C$ for all labelled maximum codes of $H$. For $C\in\mathcal C$, write $C_j\subseteq C_7^{\boxtimes 2}$ for its seven layers. For $d=2,3$ define the finite relation $$\mathcal T_d=\{(C_0\cup C_1,C_d\cup C_{d+1};C_0,C_d):C\in\mathcal C\}.$$ For the adjacent case use $$\mathcal T_A=\{(C_0\cup C_1,C_1\cup C_2;C_1,C_3):C\in\mathcal C\}.$$ Repeated relation records are immaterial. The middle-only relation is the projection of $\mathcal T_A$ that forgets $C_3$. These are exact row relations, not tests of containment in an unspecified larger code.

For a transverse axis $a$ and window $\{t,t+1\}$, restrict each known physical layer to the window and delete coordinate $a$. This gives a square row. A known cubic band projects injectively in such a window. If the full transverse band of a hypothetical code has size 33, its seven projected rows form a member of $\mathcal C$. Its known rows therefore satisfy the corresponding relation above. All labelled members are generated, so applying an isometry to normalize the first band cannot lose a trace. Equivalently, a canonical dictionary must transport both its key and every allowed split by every relevant isometry, including all stabilizers of the key. One chosen transporter or one witness per key is insufficient. These observations prove necessity of the dictionary tests.

## Physical and auxiliary variables in A

For a normalized pair $(B_0,B_1)$, put $C=B_0\cap B_1$ and $D=H\setminus N[B_1\setminus B_0]$. The physical variables are $x_w$ for $w\in C$ and $y_v$ for $v\in D$. They indicate membership in $X=A_1$ and $Y=A_3$. Every possible $Y$ is contained in $D$, since $B_1\setminus B_0\subseteq A_2$. The reconstructed prefix is $(B_0\setminus X,X,B_1\setminus X,Y)$. Clauses require $|X|=17$, $|Y|=16$, prohibit confusable pairs in $Y$, and impose $y_v\Rightarrow x_w$ for each confusable $v\in D,w\in C$. The latter implication is precisely compatibility with $A_2$. Compatibility among the first three layers follows from their two independent band unions. The five historical broader cases allow the nine count pairs specified in the shipped encoder and include $(17,16)$.

There is an auxiliary window variable $h_{a,t}$ and, for each matching record of $\mathcal T_A$, a selector $s_{a,t,r}$. The clauses impose $s_{a,t,r}\Rightarrow h_{a,t}$ and $h_{a,t}\Rightarrow\bigvee_r s_{a,t,r}$. A selected record fixes every projected middle bit. For every projected fourth-row point required by that record, exactly one available physical lift must be selected; for an absent point, all its lifts must be absent. For each axis the seven clauses $\bigvee_{t\ne j}h_{a,t}$, one for each $j$, require at least two true window variables. They do not incorrectly require the two windows to be adjacent. Auxiliary threshold variables implement the cardinalities: a state $z_{i,k}$ means at least $k$ of the first $i$ physical bits are true, with recurrence $z_{i,k}\leftrightarrow(z_{i-1,k}\vee(z_{i-1,k-1}\wedge v_i))$, true zero threshold, and false impossible thresholds. This equivalence allows every actual physical assignment to extend to threshold variables.

#### Worked two-lift clause.

Take transverse axis $a=1$, window $\{0,1\}$, and plane point $(2,4)$. Its two possible lifts in $Y$ are $(0,2,4)$ and $(1,2,4)$, with bits $y_0,y_1$, if both lie in $D$. A selected trace requiring that point contributes $(\neg s\vee y_0\vee y_1)$ and $(\neg s\vee\neg y_0\vee\neg y_1)$; one omitting it contributes $(\neg s\vee\neg y_0)$ and $(\neg s\vee\neg y_1)$. Thus $(1,0)$ and $(0,1)$ are both represented physical lifts, whereas $(0,0)$ and $(1,1)$ are disallowed when the point is required. The two lifts are themselves confusable. This local example explains the encoding; it is not asserted to be a surviving full prefix.

## A coverage invariant and refutation interface

The following pseudocode states the complete obligation; actual files use root and local scalar-pair indices to make the order unambiguous.

> For each of the 1016 first-band representatives:\
> generate all labelled second bands with overlap 16..30;\
> for every pair, regenerate the necessary middle/joint formula;\
> check its recorded refutation, or:\
> check every distinct physical prefix and its completion bound;\
> add its complete physical blocking clause;\
> check a final refutation of the blocked formula.

The invariant is that every hypothetical code maps to an unexcluded physical assignment in one of the current or remaining pair cases. A middle-only refutation is sufficient because forgetting $Y$ weakens the necessary conditions. A joint refutation excludes the whole pair. For an exhausted family, the block for physical assignment $p$ is $\bigvee_{p_i=0}v_i\vee\bigvee_{p_i=1}\neg v_i$, over all physical bits, not selector or threshold bits. It excludes precisely that physical assignment, regardless of its auxiliary representations. After all checked prefixes are blocked, a refutation proves there is no additional physical assignment. Thus neither one satisfying model nor a search status can establish exhaustion.

Each proof addition $K$ is accepted only if unit propagation on the current clause set together with all negated literals of $K$ reaches a contradiction. Hence the previous clauses entail $K$; induction makes every addition sound. The final empty clause must itself pass this test. Deletion instructions may be dropped: retaining previously justified clauses preserves the contradiction reached by unit propagation (or produces one earlier). Retention cannot make an invalid addition valid relative to a hypothetical satisfying assignment of the original formula. The replay regenerates formulas, checks exact serialized identities and literal ranges, and rejects missing, duplicate, reordered or extra scalar records and trailing proof data. Formula hashes bind a reconstruction; they do not replace its mathematical semantics.

## Ordinary N and complete cube unions

For distance $d$, each of the two bands has 33 physical Boolean variables, selecting its lower or upper outer layer. For every transverse window, $\mathcal T_d$ supplies partial assignments to the variables occurring in that window. Select every pair of windows on each of the three axes, join every combination of their allowed assignments, and discard only contradictory joins or consequences of necessary compatibility and cardinality conditions. The invariant after each join is that every hypothetical code agreeing with that window choice extends one retained partial assignment. Every target code has at least two qualifying windows per axis, so the union over choices covers it.

A partial assignment is a Boolean cube: its unset bits are unrestricted. For ordinary N, recursively try both values of each unset bit, propagating only the distance-two compatibility implications and the stated cardinality intervals. Accept a leaf exactly when all necessary conditions hold. The complete regenerated set must equal the recorded physical set; every retained prefix is then checked in the original graph and bounded by Lemma 4.1. The replay accounts for empty pairs as well as nonempty ones. Class ordering is justified by the band-swap symmetry in Section 3; all first classes and both distances must be covered.

For each of the three exceptional distance-three families, stop at the complete joined-cube union instead. Regenerate and compare that entire union and its physical variable map. For every cube compute the minimum prefix weight under the two required cardinality intervals. A fixed bit contributes its chosen lift's weight; for free bits start from one lift and sort the weight differences, considering every allowed number of selected lower lifts. The two bands have separate cardinality constraints, so their exact minima add. Ignoring other compatibility conditions only lowers the minimum. Apply 2 to every cube. This covers all extensions even though cubes may overlap and may include invalid physical prefixes. An unfinished physical enumeration is never used as an exhaustive set. A resource cap or incomplete cube cover fails the check.

The complete logical chain in both branches is $$\begin{gathered}
\text{hypothetical code}\Longrightarrow\text{normalized pair}\\
\Longrightarrow\text{represented assignment or cube}\Longrightarrow\text{contradiction}.
\end{gathered}$$

## A small exact completion example

The arithmetic can be illustrated without a large certificate. In $C_7$ fix $F=\{0\}$. The residual domain is $\{2,3,4,5\}$. Give weight one to the two capacity-one edge windows $\{2,3\}$ and $\{4,5\}$ and take $D=1$. Then the capacity sum is two, $W(0)=0$, and every residual vertex has weight one. The repair formula yields $|S|\leq2+(1-0)+0=3$. The actual four-dimensional certificates use the identical argument with 4,095 product windows and integer weights; the checker evaluates the full positive-part residual sum. If their integer numerator is $N<113D$, then $|S|\leq\lfloor N/D\rfloor\leq112$, even when $N>112D$.

## Trusted components and transferability

The proof trusts the stated graph-to-instance reductions, complete census and trace generators, RUP checker, finite allocation/cube enumeration, integer completion evaluator, and their compiler/runtime. It does not trust the search solver, floating-point discovery optimizer, or archived success labels. It is not a proof-assistant formalization. The source map in the reproduction guide points to these small logical interfaces within the larger preserved provenance.

Band projection, trace transport, physical-only blocking and integer repair bounds apply to other strong products once appropriate capacities and complete boundary catalogues are available. The seven-cycle deficit sum, mixed-cycle contraction cutoff, catalogue sizes and the specific 33-band covering argument are particular to this computation. No new bound for another cycle is inferred from transferability alone.

# B Reproduction map {#app:replay}

Extract each named ZIP into a new directory. Run these commands from its extracted root. Every `NEW` path must be fresh. The root guide `REPRODUCE.md` supplies all statuses and direct source links.

1.  Main bound, `c7-fourth-power-upper112.zip`:

        python3 -B verify.py --bundle . --out ../NEW-main

    Expected: `PASS_FRESH_MAIN112_BOUND`.

2.  Boundary traces, `c7-maximum-square-trace-extension-classification.zip`:

        python3 -O verification/replay.py --work-dir ../NEW-traces \
          --receipt ../NEW-traces.json

    Expected: `FRESH_EXACT_TRACE_CLASSIFICATION_PASS`. The four counts sum to 1,003,520.

3.  Minimum saturation, `c7-minimum-saturation112.zip`:

        python3 -B -O verify.py --work-dir ../NEW-saturation \
          --census-seconds 1200 --verification-seconds 1800

    Expected: `PASS_FRESH_RESTRICTED112_STAGED_EXCLUSION`.

4.  Square gadgets, `c7-gao-square-product-maximum106.zip`:

        python3 -B -O replay.py --work-dir ../NEW-gadgets

    Expected: `PASS_FRESH_EXACT_GAO_SQUARE_PRODUCT_MAXIMUM_106`.

5.  Moment barrier, `c7-invariant-relaxation-barrier.zip`:

        mv verification.json submitted-verification.json
        python3 -B verify.py

    Expected: `EXACT_FEASIBLE112_FOR_STATED_RELAXATION`. The rename preserves the included receipt in this fresh extraction. Check all 156,291 rows and both PSD certificates in the new receipt.

The main replay reconstructs N's cubic census, no-34 proof and mixed-77 prerequisite before N and A. Do not enable Python optimization for N or mixed-77: their assertions are checks. The top-level main driver explicitly selects the proper modes for its children. Optimized mode is supported where shown above. The original archives' resource limits are fail-closed; a timeout is not mathematical success.

Inside the main replay's extracted `components` directory, consult `A/c7-conditional-adjacent113/component/DESIGN.md`, its `MATHEMATICAL_SCOPE.md`, `src/joint_encoder.hpp` and `src/replay.cpp`; for N consult `N/runtime/PROOF_SCOPE.md`, `V3-SCALING.md`, `partition113.hpp` and `cube_arithmetic.py`. The N prerequisite directories are `runtime/dependencies/census33` and `runtime/dependencies/mixed77`; the latter's `endpoint78/PROOF_SCOPE.md` gives the complete 78-exclusion. Historical pilot-status sentences in these unchanged sources are superseded only as recorded in the dated guide, never silently rewritten.

# References {#references .unnumbered}

1.  L. D. Baumert, R. J. McEliece, E. Rodemich, H. Rumsey, R. Stanley and H. Taylor. A combinatorial packing problem. *Computers in Algebra and Number Theory*, 1971, pp.97--108. <https://oeis.org/A003012/a003012.pdf>.

2.  S. Polak and A. Schrijver. New lower bound on the Shannon capacity of $C_7$ from circular graphs. *Information Processing Letters* **143** (2019), 37--40. [doi:10.1016/j.ipl.2018.11.006](https://doi.org/10.1016/j.ipl.2018.11.006).

3.  N. Itty, C. D. Rosin, C. Carstensen and D. Reichman. Improved lower bounds for the Shannon capacity of odd cycles. arXiv:2607.21517v2, 30 July 2026. <https://arxiv.org/abs/2607.21517v2>.

4.  Y. Gao. A Recursive Construction Improving the Lower Bound on the Shannon Capacity of $C_7$. arXiv:2607.27869v1, 30 July 2026. <https://arxiv.org/abs/2607.27869v1>.

5.  A. Vesel and J. Žerovnik. Improved lower bound on the Shannon capacity of $C_7$. *Information Processing Letters* **81**(5) (2002), 277--282. [doi:10.1016/S0020-0190(01)00229-0](https://doi.org/10.1016/S0020-0190(01)00229-0).

6.  P. Buys, S. Polak and J. Zuiddam. Lean-verified lower bounds for the Shannon capacity of odd cycles. arXiv:2607.29681v1, 31 July 2026. <https://arxiv.org/abs/2607.29681v1>.
