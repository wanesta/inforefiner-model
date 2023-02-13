# -*- coding: utf-8 -*-
import pyod,joblib,numpy

def gen_data():
    contamination = 0.1  # percentage of outliers
    n_train = 200  # number of training points
    n_test = 100  # number of testing points

    # Generate sample data
    X_train, X_test, y_train, y_test = pyod.utils.data.generate_data(n_train=n_train,
                                                                     n_test=n_test,
                                                                     n_features=6,
                                                                     contamination=contamination,
                                                                     random_state=42)
    return X_train, X_test, y_train, y_test

def train_save_model(model_name,X_train):
    # train LOF detector
    clf = pyod.models.lof.LOF()
    clf.fit(X_train)

    # save the model
    joblib.dump(clf, model_name)
    return clf

def load_model_predict(X_test):
    model_path = '/home/gaosm/Downloads/dev-1/pytest/clf1.joblib'
    test_X = numpy.array(X_test)
    clf = joblib.load(model_path)
    y_test_pred = clf.predict(test_X)
    lst = y_test_pred.tolist()
    print('predict result  {}'.format(lst))
    return [lst]


def szSecTest(List):
    print(List)
    IntegerList = [[1, 2, 3], [2, 3, 4]]
    return IntegerList