import pandas as pd
import numpy as np

def load_cpt(file_path):
    return pd.read_csv('..\\CPT\\'+file_path)

cpt_ha = load_cpt('CPT_Happy.csv')
cpt_su = load_cpt('CPT_Success.csv')
cpt_hw = load_cpt('CPT_HW.csv')
cpt_pa = load_cpt('CPT_Party.csv')
cpt_sm = load_cpt('CPT_Smart.csv')
cpt_cr = load_cpt('CPT_Creative.csv')
cpt_mu = load_cpt('CPT_Music.csv')
cpt_pr = load_cpt('CPT_Project.csv')

def get_prob(cpt, conditions=None):
    if conditions is None:
        return float(cpt.iloc[0, 0])
    
    row = cpt
    for col, val in conditions.items():
        row = row[row[col] == val]
    
    return float(row.iloc[0, -1])

def calculate_p_ha():
    p_ha = 0.0
    
    p_pa = get_prob(cpt_pa)
    p_sm = get_prob(cpt_sm)
    p_cr = get_prob(cpt_cr)
    
    for pa in [True, False]:
        p_pa = p_pa if pa else 1 - p_pa
        for sm in [True, False]:
            p_sm = p_sm if sm else 1 - p_sm
            for cr in [True, False]:
                p_cr = p_cr if cr else 1 - p_cr
                p_hw_on_pa_sm = get_prob(cpt_hw, {'Party': 'T' if pa else 'F', 
                                                        'Smart': 'T' if sm else 'F'})
                for hw in [True, False]:
                    p_hw = p_hw_on_pa_sm if hw else 1 - p_hw_on_pa_sm
                    p_pr_on_sm_cr = get_prob(cpt_pr, {'Smart': 'T' if sm else 'F',
                                                        'Creative': 'T' if cr else 'F'})
                    for pr in [True, False]:
                        p_pr = p_pr_on_sm_cr if pr else 1 - p_pr_on_sm_cr
                        p_su_on_hw_pr = get_prob(cpt_su, {'HW': 'T' if hw else 'F',
                                                                        'Project': 'T' if pr else 'F'})
                        for su in [True, False]:
                            p_su = p_su_on_hw_pr if su else 1 - p_su_on_hw_pr
                            p_mu_on_sm_cr = get_prob(cpt_mu, {'Smart': 'T' if sm else 'F', 
                                                                'Creative': 'T' if cr else 'F'})
                            for mu in [True, False]:
                                p_mu = p_mu_on_sm_cr if mu else 1 - p_mu_on_sm_cr
                                p_ha_on_pa_mu_su = get_prob(cpt_ha, {'Party': 'T' if pa else 'F',
                                                                        'Music': 'T' if mu else 'F',
                                                                        'Success': 'T' if su else 'F'})
                                joint_prob = p_pa * p_sm * p_cr * p_hw * p_pr * p_su * p_mu * p_ha_on_pa_mu_su
                                p_ha += joint_prob
    
    return p_ha

if __name__ == "__main__":
    print(f"P(Happy = 1) = {calculate_p_ha():.6f}")