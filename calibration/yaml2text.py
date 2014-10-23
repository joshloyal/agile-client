"""
yaml2text -- Convert yaml calibration files to simple text files
Author: Joshua Loyal
email: joshua.d.loyal@gmail.com
"""

import yaml

class NetParser():
    def __init__(self):
        self.has_branches = False
        self.has_inputs = False
        self.has_targets = False
        self.has_scaling = False
        self.has_outputs = False
        self.has_binning = False
        self.branches = None
        self.inputs = None
        self.binning = None
        self.outputs = None
        self.architecture = None
    
    def load(self, filename):
        """
        """
        self.has_branches = False
        self.has_inputs = False
        self.has_targets = False
        self.has_scaling = False
        self.has_outputs = False
        self.has_binning = False
        self.branches = None
        self.inputs = None
        self.binning = None
        self.outputs = None
        self.architecture = None

        with open(filename, 'r') as f:
            y = yaml.load(f.read())
        if y.has_key('branches'):
            self.branches = y['branches'].keys()
            self.has_branches = True

        if y['network'].has_key('input_order'):
            self.inputs = y['network']['input_order']
            self.has_inputs = True

        if y.has_key('binning'):
            self.binning = y['binning']
            self.has_binning = True

        if y['network'].has_key('target_order'):
            self.outputs = y['network']['target_order']
            self.has_targets = True

        self.architecture = [ Layer(y['network'][idx]) 
                                for idx in y['network']['layer_access']]

    def write(self, filename):
        with open(filename, 'w') as f:
            # write inputs
            if self.has_inputs:
                for i in self.inputs:
                    f.write(i+'|')
                f.write('\n')

            # write outputs
            if self.has_targets:
                for o in self.outputs:
                    f.write(o+'|')
                f.write('\n')
            
            # write the layers
            for layer in self.architecture:
                f.write( str(layer.inputs)+'|' )
                f.write( str(layer.outputs)+'|' )
                f.write( layer.activation+'|' )
                f.write( layer.weights+'|' )
                f.write( layer.bias+'|' )
                f.write('\n')
class Layer():
    def __init__(self, y):
        self.inputs  = y['inputs']
        self.outputs = y['outputs']
        self.activation = y['activation']
        self.weights = y['weights'][y['weights'].find(',')+1:]
        self.bias    = y['bias'][y['bias'].find(',')+1:]

if __name__ == '__main__':
    p = NetParser()
    #p.load('BigDumbGAIA.yaml')
    p.load('VHbb_tagger.yaml')
    p.write('test.txt')
