import System.IO
import Control.Monad
import Data.Matrix

convertToDouble :: [String] -> [Double]
convertToDouble = map read

getNorm :: Matrix Double -> Double
getNorm arrMat =  sqrt(sum [x*x | x <- (toList arrMat)])


gradientDescent :: Double -> Double -> Matrix Double -> Matrix Double -> (Matrix Double -> Matrix Double) -> Matrix Double
gradientDescent accuracy learningRate thetaPrev theta fGrad
  | (getNorm(theta-thetaPrev) > accuracy) = gradientDescent accuracy learningRate theta (theta - scaleMatrix learningRate (fGrad theta)) fGrad
  | otherwise = theta

gradientDescentByIt :: Int -> Double -> Matrix Double -> (Matrix Double -> Matrix Double) -> Matrix Double
gradientDescentByIt numIter learningRate theta fGrad
  | (numIter >= 1) = gradientDescentByIt (numIter-1) learningRate (theta - scaleMatrix learningRate (fGrad theta)) fGrad
  | otherwise = theta

main = do
  let contents = readFile "dataset.txt"
  stringArray <- fmap lines contents
  let stringData = map words stringArray
  let datasetList = map convertToDouble stringData
  let dataset = fromLists datasetList
  let numData = nrows dataset 
  putStrLn ("Number of data: " ++ show numData)
  let regressors = mapCol (\_ x -> x + 1) 1 ((zero numData 1) <|> (submatrix 1 numData 1 2 dataset))
  let output = submatrix 1 numData 3 3 dataset
  let initialTheta = zero (ncols regressors) 1
  putStrLn ("Initial theta: ")
  print initialTheta
  let calculateGradient index grad theta = do
                       if (index >= 1) 
                       then do
                         let currentRow = rowVector (getRow index regressors)
                         let a_sig = multStd2 currentRow theta 
                         let pi_hat = sigmoid (a_sig ! (1,1))
                         calculateGradient (index-1) (grad + scaleMatrix (pi_hat - (output ! (index,1))) (transpose currentRow)) theta
                       else 
                         grad
  let gradFunction theta = calculateGradient numData (zero (ncols regressors) 1) theta

  let thetaHat = gradientDescent 1.0 0.01 (mapCol (\_ x -> x - 10) 1 initialTheta) initialTheta gradFunction    
  putStrLn $ "Estimated parameters by accuracy: "
  print thetaHat

  let thetaHatIt = gradientDescentByIt 5000 0.01 initialTheta gradFunction    
  putStrLn $ "Estimated parameters by iterations: "
  print thetaHatIt

  let esitmatedFunction w h = sigmoid((thetaHat ! (1,1)) + (thetaHat ! (2,1))*w + (thetaHat ! (3,1))*h)
  let classificate w h | ((esitmatedFunction w h) <= 0.5) = "L'animale è un gatto! :(" | otherwise = "L'animale è un cane! :)"
  let repeatInput = do
        putStrLn "Inserisci il peso [Kg]: "
        weight <- getLine 
        putStrLn "Inserisci l'altezza [cm]: "
        height <- getLine  
        if (((read weight :: Double) > 0) && ((read height :: Double) > 0)) 
        then do
          putStrLn (classificate (read weight :: Double) (read height :: Double))
          repeatInput
        else
          return()
  
  repeatInput
  putStrLn "Arrivederci!"
  

sigmoid :: Double -> Double
sigmoid z = 1/(1 + exp((-z)))