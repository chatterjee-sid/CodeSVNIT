import pandas as pd
import itertools

df = pd.read_csv("LAB_10_student.csv", header=None)

cpt_structure = {
    "Party": [],
    "Smart": [],
    "Creative": [],
    "HW": [0, 1],             # HW | Party, Smart
    "Music": [1, 2],          # Music | Smart, Creative
    "Project": [1, 2],        # Project | Smart, Creative
    "Success": [3, 5],        # Success | HW, Project
    "Happy": [0, 4, 6],       # Happy | Party, Music, Success
}

column_names = {
    0: "Party",
    1: "Smart",
    2: "Creative",
    3: "HW",
    4: "Music",
    5: "Project",
    6: "Success",
    7: "Happy"
}

name_to_col = {v: k for k, v in column_names.items()}

for node_name, parents in cpt_structure.items():
    node_col = name_to_col[node_name]
    parent_names = [column_names[p] for p in parents]
    rows = []
    
    for values in itertools.product(['T', 'F'], repeat=len(parents)):
        mask = pd.Series([True] * len(df))
        arb = {'T':1, 'F':0}
        for col_index, val in zip(parents, values):
            mask &= (df[col_index] == arb[val])
        
        total = mask.sum()
        count_1 = ((df[node_col] == 1) & mask).sum()
        
        prob = (count_1 + 1) / (total + 2)
        
        row = list(values) + [round(prob, 3)]
        rows.append(row)

    cpt_df = pd.DataFrame(rows, columns=parent_names + [f"P({node_name}=1 | {','.join(parent_names)})" if parents else f"P({node_name}=1)"])
    
    cpt_df.to_csv(f"CPT_{node_name}.csv", index=False)
    print(f"Saved CPT for {node_name} to CPT_{node_name}.csv")
