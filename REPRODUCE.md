# Reproduction and proof-source map

Use Python3.10+ and fresh output paths. Extract each ZIP under `evidence/` to a new workspace, then enter its root. No SAT or numerical optimizer is required. Main replay needs C++17 with unsigned128, macOS CommonCrypto or Linux OpenSSL development headers, and at least20GiB free space. Keep that reserve throughout the run. Resource limits fail closed.

## Main upper112 theorem and its prerequisites

```sh
python3 -B verify.py --bundle . --out ../NEW-main
```

Expected `NEW-main/result.json`: `PASS_FRESH_MAIN112_BOUND`, lower108, upper112, exact optimum unknown. The driver runs N with assertions enabled, then A with its explicitly supported optimized mode. Do not globally force `-O` on N or mixed77.

Nested components are extracted by this command. Within `NEW-main/components/` the relevant specifications and trusted sources are:

- `A/c7-conditional-adjacent113/component/DESIGN.md`: record semantics and acceptance interface.
- `A/c7-conditional-adjacent113/component/MATHEMATICAL_SCOPE.md`: conditional graph reduction.
- `A/c7-conditional-adjacent113/component/src/joint_encoder.hpp`: X/Y physical bits, trace selectors, cardinality equivalences.
- `A/c7-conditional-adjacent113/component/src/replay.cpp`: formula reconstruction and RUP/completion checks.
- `N/runtime/PROOF_SCOPE.md`: graph-to-trace/allocation semantics; its pilot scope is superseded as explained in SUPERSESSION.md.
- `N/runtime/V3-SCALING.md`, `replay_all.py`, `partition113.hpp`: complete1016-root coverage and table joins.
- `N/runtime/cube_arithmetic.py`: exact uniform bounds on complete cube unions.
- `N/runtime/dependencies/census33/README.md` and `assurance/independent-audit.md`: complete cubic census and orbit interpretation.
- `N/runtime/dependencies/mixed77/endpoint78/PROOF_SCOPE.md`: complete mixed78 exclusion.

Prerequisites can also be run separately from their own package roots:

```sh
# census33; expected FRESH_EXACT_CENSUS_REPLAY_PASS
python3 -O verification/replay.py --work-dir ../NEW-census --receipt ../NEW-census.json
# mixed77; expected PASS_FRESH_EXACT_UPPER77; assertions must stay enabled
python3 verify.py --out ../NEW-mixed77.json
```

## Complete maximum-square traces

Root: `c7-maximum-square-trace-extension-classification`.

```sh
python3 -O verification/replay.py --work-dir ../NEW-traces --receipt ../NEW-traces.json
```

Expected: `FRESH_EXACT_TRACE_CLASSIFICATION_PASS`. Counts for maxima30,31,32,33 are1960,29008,709128,263424, total1003520. This includes the full cubic census and exceptional exclusions, not all cubic32 codes.

## Minimum-saturation112 exclusion

Root: `c7-minimum-saturation112`.

```sh
python3 -B -O verify.py --work-dir ../NEW-saturation --census-seconds 1200 --verification-seconds 1800
```

Expected: `PASS_FRESH_RESTRICTED112_STAGED_EXCLUSION`, complete restricted census11175 and survivor counts11175→43→0. `PASS_FRESH_RESTRICTED112_REDUCTION_WITH_SURVIVORS` would not prove the stated exclusion. Inspect both full proof passes; calibration and exploratory samples are not substitutes.

## Square-factor gadget maximum106

Root: `gao-square-method106`.

```sh
python3 -B -O replay.py --work-dir ../NEW-gadgets
```

Expected: `PASS_FRESH_EXACT_GAO_SQUARE_PRODUCT_MAXIMUM_106`. This is a construction-specific maximum, not an unrestricted graph bound.

## Two-block moment relaxation

Root: `c7-invariant-relaxation-barrier`. Preserve the included receipt under a new name within this fresh extraction:

```sh
mv verification.json submitted-verification.json
python3 -B verify.py
```

Expected new `verification.json`: `EXACT_FEASIBLE112_FOR_STATED_RELAXATION`; all156291 linear rows and the31/35 compressed PSD certificates pass. The paper proves thinning to109–111. To check optimized mode too, preserve this new receipt before rerunning with `python3 -B -O verify.py`. No actual independent code follows from pseudo-moment feasibility.

## Quick outer checks

From the outer release root:

```sh
python3 -B verify_bundle.py
python3 -B -O verify_bundle.py
```

These verify manifests, original nested archive identities, the108 witness, normalization. The separate package gate also runs corruption controls. They do not rerun the long mathematical components. See the acceptance receipts for the full fresh runs and their source/environment bindings.

## Direct specification links

The following exact-byte extracts are convenient reading copies; executable replay uses the original nested archives. Their [source map](guides/specifications/SOURCE_MAP.json) binds original paths and hashes.

- [A-DESIGN.md](guides/specifications/A-DESIGN.md)
- [A-MATHEMATICAL_SCOPE.md](guides/specifications/A-MATHEMATICAL_SCOPE.md)
- [A-joint_encoder.hpp](guides/specifications/A-joint_encoder.hpp)
- [A-replay.cpp](guides/specifications/A-replay.cpp)
- [N-PROOF_SCOPE.md](guides/specifications/N-PROOF_SCOPE.md)
- [N-V3-SCALING.md](guides/specifications/N-V3-SCALING.md)
- [N-partition113.hpp](guides/specifications/N-partition113.hpp)
- [N-cube_arithmetic.py](guides/specifications/N-cube_arithmetic.py)
- [census33-README.md](guides/specifications/census33-README.md)
- [mixed77-PROOF_SCOPE.md](guides/specifications/mixed77-PROOF_SCOPE.md)
