import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (
    accuracy_score,
    classification_report,
    confusion_matrix
)
df = pd.read_csv("./AI_Project/customer_purchase_data.csv")

X = df.drop("purchased",axis = 1)
y = df["purchased"]

X_train,X_test,y_train,y_test = train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=11,
    stratify=y
)

#chia num va cate
numeric_features =[
    "age",
    "income",
    "website_time",
    "pages_visited",
    "previous_purchases"
]
categorical_features = [
    "discount",
    "device",
    "gender"
]

#num va cate ( pipe )
numeric_pipeline=Pipeline([
    ("imputer",SimpleImputer(strategy="median")),
    ("scaler",StandardScaler())
])
categorical_pipeline=Pipeline([
    ("imputer",SimpleImputer(strategy="most_frequent")),
    ("scaler",OneHotEncoder(handle_unknown="ignore"))
])

#colum trans
preprocessor = ColumnTransformer([
    ("num", numeric_pipeline, numeric_features),
    ("cat", categorical_pipeline, categorical_features)
])
#model
model = Pipeline([
    ("processor",preprocessor),
    ("classifer",LogisticRegression())
])
#fit
model.fit(X_train, y_train)
#predict
y_pred = model.predict(X_test)
# Accuracy
accuracy = accuracy_score(y_test, y_pred)

print("Accuracy:", accuracy)

# Classification report
print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# Confusion matrix
print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))