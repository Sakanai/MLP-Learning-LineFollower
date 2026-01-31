# MLP Learning - Line Follower Robot

This repository contains my learning process and implementation of a **Multi-Layer Perceptron (MLP)** to support a **Line Follower Robot (LFR)** system in predicting/classifying turn directions based on sensor data.

### CLASSIFICATION
0.   SHARP RIGHT TURN  
1.   SHARP LEFT TURN  
2.   RIGHT ANGLE TURN  
3.   LEFT ANGLE TURN  

---

## A. Project Goals
The purpose of this project is to:

- Learn the basic concepts and workflow of **MLP (Multi-Layer Perceptron)** from dataset preparation to model evaluation.
- Perform **EDA (Exploratory Data Analysis)** on the LFR dataset to better understand the data patterns.
- Apply **data preprocessing & transformation** to make the dataset ready for training.
- Train an MLP model to predict the required output for the line follower robot.
- Test and evaluate the model performance using a dedicated evaluation/testing notebook.

---

## B. Notebook Execution Order
To ensure a structured workflow and consistent results, run the notebooks in the following order:

1. **[2] Dataset EDA**
   - `02_eda_lfr_dataset.ipynb`

2. **[3] Model Training**
   - `03_train_mlp_linefollower.ipynb`

3. **[4] Testing / Evaluation**
   - `04_evaluate_mlp_model.ipynb`

📌 Note:  
Notebook **[1] `01_mlp_from_scratch_basics.ipynb`** is optional since it is only used to learn the basic neural network concepts as a foundation.

---

## C. How to Run (Google Colab)
This repository is structured so that all notebook file paths will work correctly **if the repo folder is placed inside Google Drive** at the following location:

📌 **Google Drive → `Colab Notebooks/mlp-learning-linefollower/`**

### Steps:
1. Download this repository folder (**`mlp-learning-linefollower`**)
2. Upload/place the folder into:
   - `MyDrive/Colab Notebooks/`
3. Open the notebooks inside the `notebooks/` folder using Google Colab
4. Make sure to mount Google Drive in Colab before running the code

---

## D. Repository Structure
mlp-learning-linefollower/
│
├── data/
│   ├── linefollower_dataset.csv
│   └── linefollower_dataset_transformed.csv
│
├── models/
│   ├── model.h5
│   └── scaler.pkl
│
├── notebooks/
│   ├── 01_mlp_from_scratch_basics.ipynb
│   ├── 02_eda_lfr_dataset.ipynb
│   ├── 03_train_mlp_linefollower.ipynb
│   └── 04_evaluate_mlp_model.ipynb
│
├── robot/
│   ├── linefollower_data_logger
│   │   └── linefollower_data_logger.ino
│   └── collect_linefollower_data.py
│
└── README.md
