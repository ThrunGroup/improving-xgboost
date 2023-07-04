from xgboost import XGBClassifier
# read data
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

data = load_iris()
X_train, X_test, y_train, y_test = train_test_split(data['data'], data['target'], test_size=.2)
# create model instance

X_train, X_test = X_train[:, 0:1], X_test[:, 0:1]


bst = XGBClassifier(n_estimators=1, max_depth=1, learning_rate=1, objective='binary:logistic', tree_method="hist")


bst.fit(X_train, y_train)
# make predictions
preds = bst.predict(X_test)

print(preds)
