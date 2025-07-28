import json

input_file = "Cert_Collisions2023_366442_370790_Golden.json"
output_file = "good_lumis_2023.txt"

run_lumi_pairs = []

with open(input_file, 'r') as f:
    golden_json = json.load(f)

for run_str, lumi_ranges in golden_json.items():
    run = int(run_str)
    for start_lumi, end_lumi in lumi_ranges:
        for lumi in range(start_lumi, end_lumi + 1):
            run_lumi_pairs.append((run, lumi))

with open(output_file, 'w') as f:
    for run, lumi in run_lumi_pairs:
        f.write(f"{run} {lumi}\n")

print(f"Saved {len(run_lumi_pairs)} run-lumi pairs to '{output_file}'")
