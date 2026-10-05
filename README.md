# An upper bound of 112 for the fourth strong power of the seven-cycle

Anonymous · v0.1.0-candidate · 5 October 2026 · DOI [10.5281/zenodo.23160075](https://doi.org/10.5281/zenodo.23160075)

**108≤α(C₇^⊠4)≤112. The exact independence number remains open.**
The computer-assisted upper bound excludes every 113-word independent set. It lowers the historical upper endpoint 115 recorded by Polak and Schrijver (2019). The known lower bound 108 is reproduced, not claimed as new.

Read the [paper](paper/paper.pdf), [LaTeX source](paper/paper.tex), or [consistently numbered Markdown](paper/paper.md). The paper includes explicit finite-proof semantics and coverage invariants, named prerequisite results, worked examples and a complete reproduction map.

## Main evidence

The unchanged [main certificate](evidence/c7-fourth-power-upper112.zip) contains complete adjacent and nonadjacent allocation components, the complete cubic census, the no 34 and mixed 77 prerequisites, and exact integer completion checkers. The [claim map](CLAIMS.json) distinguishes every main and auxiliary conclusion.

The versioned release bundle includes all nested ZIPs. To keep the Git repository inspectable, the large certificate ZIPs are supplied as release assets inside the evidence bundle rather than Git blobs. A Git clone alone is not the complete evidence payload. Download the bundle from the [GitHub release](https://github.com/ipitchford/seven-cycle-fourth-power-upper112/releases/tag/v0.1.0-candidate) or [Zenodo record](https://zenodo.org/records/23160075), and verify its published SHA256SUMS before extraction.

## Replay

From the extracted outer bundle:

```sh
python3 -B verify_bundle.py
python3 -B verify_bundle.py --full --work-dir /absolute/path/to/NEW-replay
```

The first command checks exact bytes, the 108 witness and normalization. The second performs the full main mathematical replay. It needs Python 3.10+, a C++17 compiler with unsigned 128, and at least 20 GiB free disk throughout. Linux needs OpenSSL development headers/library; macOS uses system CommonCrypto. Allow about two hours on comparable hardware. No SAT solver or numerical optimizer is required.

[REPRODUCE.md](REPRODUCE.md) collects every auxiliary command, expected terminal status and direct proof-source link. The repository CI runs only the lower-witness/normalization smoke checks and negative controls; it is explicitly not the full upper-bound replay. The acceptance records identify the complete mathematical runs separately.

## Review response and scope

The supplied AI-assisted review requested explicit proof semantics, prerequisite provenance, literature updates and full acceptance replays. See the [response](REVIEW_RESPONSE.md), [assurance boundary](ASSURANCE.md), [provenance](PROVENANCE.md) and [supersession guide](SUPERSESSION.md). Earlier archives and their original status notes remain unchanged.

Auxiliary results are scoped: maximum-square traces are not all cubic 32 codes; minimum-saturation exclusion does not eliminate every 112 code; maximum 106 concerns two square-factor gadgets; the feasible two-block moment relaxation does not construct any code. No 109 construction or 109 exclusion is obtained, and the numerical stronger-matrix experiment remains inconclusive.

This is an unrefereed candidate. No unaffiliated reproduction, formal verification, external specialist acceptance, official research rating, or exhaustive priority finding is claimed. A DOI and public availability are not correctness guarantees.

Original prose/data CC0-1.0; original code MIT; inherited notices preserved. See [LICENSES.md](LICENSES.md). [AI_INDEX.md](AI_INDEX.md) supplies the machine-readable reading order.
