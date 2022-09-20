package main

import (
	"testing"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"
)

func TestGoTesting(t *testing.T) {
	RegisterFailHandler(Fail)
	RunSpecs(t, "GoTesting Suite")
}

var _ = Describe("testing", func() {
	It("return match not found", func() {
		Expect(PrintName()).To(Equal("testing"), "test failed")
	})

})
